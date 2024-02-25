from selenium import webdriver
from selenium.webdriver.common.by import By
import time
import requests
import cv2
import numpy as np
import serial
from sound import audio

ser = serial.Serial('COM8', 9600, timeout=1)

    # ser.write("a".encode())
    



classes = ["hrat 1","hrat 2","hrat 3"]
result = [0,0,0,0,0,0]
font = cv2.FONT_HERSHEY_SIMPLEX



def obj_run(img):
    img = cv2.resize(img, None, fx=0.6, fy=0.6)
    height, width, channels = img.shape

    print("hrat 1")
    net = cv2.dnn.readNet(r"C:\Users\Lenovo\Desktop\obj\yolov3.cfg", r"C:\Users\Lenovo\Desktop\obj\hrat_1.weights")
    layer_names = net.getLayerNames()
    output_layers = [layer_names[i - 1] for i in net.getUnconnectedOutLayers()]
    blob = cv2.dnn.blobFromImage(img, 0.00392, (416, 416), (0, 0, 0), True, crop=False)

    net.setInput(blob)
    outs = net.forward(output_layers)


    confidences = []
    boxes = []
    for out in outs:
        for detection in out:
            scores = detection[5:]
            class_id = np.argmax(scores)
            confidence = scores[class_id]
            if confidence > 0.3:
                # Object detected  
                center_x = int(detection[0] * width)
                center_y = int(detection[1] * height)
                w = int(detection[2] * width)
                h = int(detection[3] * height)

                # Rectangle coordinates
                x = int(center_x - w / 2)
                y = int(center_y - h / 2)
                boxes.append([x, y, w, h])
                confidences.append(float(confidence))
                

    indexes = cv2.dnn.NMSBoxes(boxes, confidences, 0.5, 0.4)
    font = cv2.FONT_HERSHEY_PLAIN
    for i in range(len(boxes)):
        
        if i in indexes:
            result[2] = result[2]+1
            x, y, w, h = boxes[i]
            label = str(classes[0])
            color = [0,0,255]
            cv2.rectangle(img, (x, y), (x + w, y + h), color, 2)
            cv2.putText(img, label, (x, y-5), font, 2, color, 2)


    print("hrat 2")
    net = cv2.dnn.readNet(r"C:\Users\Lenovo\Desktop\obj\yolov3.cfg", r"C:\Users\Lenovo\Desktop\obj\hrat_2.weights")
    layer_names = net.getLayerNames()
    output_layers = [layer_names[i - 1] for i in net.getUnconnectedOutLayers()]
    blob = cv2.dnn.blobFromImage(img, 0.00392, (416, 416), (0, 0, 0), True, crop=False)

    net.setInput(blob)
    outs = net.forward(output_layers)


    confidences = []
    boxes = []
    for out in outs:
        for detection in out:
            scores = detection[5:]
            class_id = np.argmax(scores)
            confidence = scores[class_id]
            if confidence > 0.3:
                # Object detected  
                center_x = int(detection[0] * width)
                center_y = int(detection[1] * height)
                w = int(detection[2] * width)
                h = int(detection[3] * height)

                # Rectangle coordinates
                x = int(center_x - w / 2)
                y = int(center_y - h / 2)
                boxes.append([x, y, w, h])
                confidences.append(float(confidence))
                

    indexes = cv2.dnn.NMSBoxes(boxes, confidences, 0.5, 0.4)
    font = cv2.FONT_HERSHEY_PLAIN
    for i in range(len(boxes)):
        
        if i in indexes:
            result[2] = result[2]+1
            x, y, w, h = boxes[i]
            label = str(classes[1])
            color = [0,0,255]
            cv2.rectangle(img, (x, y), (x + w, y + h), color, 2)
            cv2.putText(img, label, (x, y-5), font, 2, color, 2)


    print("hrat 3")
    net = cv2.dnn.readNet(r"C:\Users\Lenovo\Desktop\obj\yolov3.cfg", r"C:\Users\Lenovo\Desktop\obj\hrat_3.weights")
    layer_names = net.getLayerNames()
    output_layers = [layer_names[i - 1] for i in net.getUnconnectedOutLayers()]
    blob = cv2.dnn.blobFromImage(img, 0.00392, (416, 416), (0, 0, 0), True, crop=False)

    net.setInput(blob)
    outs = net.forward(output_layers)


    confidences = []
    boxes = []
    for out in outs:
        for detection in out:
            scores = detection[5:]
            class_id = np.argmax(scores)
            confidence = scores[class_id]
            if confidence > 0.3:
                # Object detected  
                center_x = int(detection[0] * width)
                center_y = int(detection[1] * height)
                w = int(detection[2] * width)
                h = int(detection[3] * height)

                # Rectangle coordinates
                x = int(center_x - w / 2)
                y = int(center_y - h / 2)
                boxes.append([x, y, w, h])
                confidences.append(float(confidence))
                

    indexes = cv2.dnn.NMSBoxes(boxes, confidences, 0.5, 0.4)
    font = cv2.FONT_HERSHEY_PLAIN
    for i in range(len(boxes)):
        
        if i in indexes:
            result[2] = result[2]+1
            x, y, w, h = boxes[i]
            label = str(classes[2])
            color = [0,0,255]
            cv2.rectangle(img, (x, y), (x + w, y + h), color, 2)
            cv2.putText(img, label, (x, y-5), font, 2, color, 2)


    cv2.imshow("Image", img)

    cv2.waitKey(0)

def obj_detection():

    driver = webdriver.Chrome("C:\Program Files (x86)\chromedriver.exe")
    driver.get("http://192.168.43.87")

    print(22)
    time.sleep(2)
    el = driver.find_element(By.XPATH, '/html/body/div[1]/p[2]/button[2]')
    el.click()
    print(111)
    while 1:
        el = driver.find_element(By.XPATH, '/html/body/p/span')
        text = el.text
        if text == "1": break

    el = driver.find_element(By.XPATH, '/html/body/div[1]/p[2]/button[3]')
    el.click()

    url = 'http://192.168.43.87/saved-photo'
    data = requests.get(url)

    img = cv2.imdecode(np.frombuffer( data.content, np.uint8), 1)
    # width = int(frame1.shape[1] /2)
    # height = int(frame1.shape[0] /2)
    # dsize = (width, height)
    # cap = cv2.resize(frame1, dsize)

    obj_run(img)
    ser.write(b';\r\n')
    print("end")
e = audio()
print("wait")
a = ser.readline()
n = 0
ar = []
fl = 0
while 1:
    print(a, "wait")
    a = ser.readline()
    if a == b'1\r\n':
        obj_detection()
    else:
        try:
            # e.findnumber(int(a) % 1000,"a")
            if len(ar) < 3:
                fl = 0
                n = 0
                ar.append([int(int(a)/1000), int(a) % 1000])
            else: 
                if fl == 0:
                    fl = 1
                    print(ar)
                    e.findnumber(ar[0][1],'a')
                    
                    e.findnumber(ar[1][1],'f')
                    
                    e.findnumber(ar[2][1],'k')
                    
                    ar = []
                    
            print(int(int(a)/1000), int(a) % 1000)
                
        except:
            pass
# while 1:
#     el = driver.find_element(By.XPATH, '/html/body/p/span')
#     text = el.text
#     print(text)
#     time.sleep(1)
#     if text == 1: break
# cou = 0
# while 1:
#     el = driver.find_element(By.XPATH, '/html/body/p/span')
#     text = el.text
#     # print(text)
#     if len(text) == 4 and text[0] == '3' and cou < 1:
#         print(int(text[1:]))
#         cou = cou +1
#         # el = driver.find_element(By.XPATH, '/html/body/div[1]/p[2]/button[3]')
#         # el.click()
#     if len(text) == 4 and text[0] == '4' and cou < 2:
#         print(int(text[1:]))
#         cou = cou +1
#     if len(text) == 4 and text[0] == '6' and cou < 3:
#         print(int(text[1:]))
#         cou = cou +1
#     if text == "12593":
#         time.sleep(65)
#         obj_detection()
#         break

# obj_run(cv2.imread(r"D:\pyton_object_detection\space detection\test\msg1232449124-4319.jpg"))

