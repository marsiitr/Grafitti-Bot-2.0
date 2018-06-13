import numpy as np
import cv2
import serial

def main():
    img = cv2.imread('iitr.jpg',0)
    npix=1+int(max(img.shape[1],img.shape[0])/110)
    dim=(int(img.shape[1]/npix),int(img.shape[0]/npix))

    ret,th1 = cv2.threshold(img,127,255,cv2.THRESH_BINARY)
    ret,thresh1 = cv2.threshold(img,127,255,cv2.THRESH_BINARY)
    resize1 = cv2.resize(thresh1,dim,interpolation=cv2.INTER_NEAREST)
    resize2 = cv2.resize(resize1,(thresh1.shape[1],thresh1.shape[0]),interpolation=cv2.INTER_NEAREST)
    edges=cv2.Canny(img,127,255)
    ret,thresh2 = cv2.threshold(edges,127,255,cv2.THRESH_BINARY_INV)

    params = cv2.SimpleBlobDetector_Params()

    # Filter by Area.
    params.filterByArea = True
    params.minArea=0
    params.maxArea = 100

    detector=cv2.SimpleBlobDetector_create(params)
    keypoints=detector.detect(resize2)
    im_with_keypoints = cv2.drawKeypoints(resize2, keypoints, np.array([]), (0,0,255), cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)
     
    # Show keypoints
    #cv2.imshow("Keypoints", im_with_keypoints)
    #pix=img[int(img.shape[1]/npix),int(img.shape[0]/npix)]
    for kp in keypoints:
        cv2.circle(resize2, (int(kp.pt[0]), int(kp.pt[1])), int(kp.size), (255,255,255),cv2.FILLED,8,0)
        
    #cv2.imshow("blobed", resize2) 

    #for i in range(0,int(img.shape[0]-npix),npix):
     # for j in range(0,int(img.shape[1]-npix),npix):
      #  for r in range(npix):
       #   resize2[i+r,j] = 0
        #  resize2[i,j+r] = 0

    #cv2.imshow("Original",img)
    #cv2.imshow("THRESH_BINARY",thresh1)
    #cv2.imshow("edge",edges)
    #cv2.imshow("THRESH_BINARY_INV",thresh2)
    cv2.imshow("pixelated",resize2)

    ser=serial.Serial('com6',9600)
    k=ser.readline().decode()

    alternate=False
    for x in range(int(npix/2),int(img.shape[1]),npix):
        if alternate==False:
            alternate=True
        else:
            alternate=False
        for y in range(int(npix/2),int(img.shape[0]),npix):
            if alternate==True:
                yc=int(img.shape[0])-y
                
            if resize2[yc,x]==0:
                print(str(x)+'#'+str(yc)+'#'+str(resize2[yc,x]))
                ser.write((str(x/npix)+'#'+str(yc/npix)+'#'+str(resize2[yc,x])+'\n').encode('utf-8'))
                k='B'
                print (k)
                k=ser.readline().decode()
                print(k)
                if(k[0]=='A'): continue
                else:
                    while(k[0]!='A'):
                        print(k)
                        k=ser.readline().decode()
                    print(k)
            

if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        ser.close()
        cv2.waitKey(0)
        cv2.destroyAllWindows()

