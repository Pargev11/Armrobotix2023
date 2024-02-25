import cv2
import numpy as np

classes = ["hrat 1","hrat 2","hrat 3"]
result = [0,0,0,0,0,0]
font = cv2.FONT_HERSHEY_SIMPLEX


img = cv2.imread(r"C:\Users\Lenovo\Desktop\photo.jpg")
img = cv2.resize(img, None, fx=0.5, fy=0.5)

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
net = cv2.dnn.readNet(r"C:\Users\Lenovo\Desktop\obj\yolov3.cfg", r"C:\Users\Lenovo\Desktop\obj\yolov3_custom_last.weights")
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