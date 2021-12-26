
from imageai.Detection import ObjectDetection
import os

execution_path = os.getcwd()
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'
detector = ObjectDetection()
detector.setModelTypeAsTinyYOLOv3()
detector.setModelPath(os.path.join(execution_path , "yolo-tiny.h5"))
detector.loadModel()
detections = detector.detectObjectsFromImage(input_image=os.path.join(execution_path , "elmalar.jpg"), output_image_path=os.path.join(execution_path , "elmaolacaksahislar.jpg"), minimum_percentage_probability=30)

for eachObject in detections:
    print(eachObject["name"] , " : ", eachObject["percentage_probability"], " : ", eachObject["box_points"])
    print("--------------------------------")