from imageai.Detection import ObjectDetection
tarayici = ObjectDetection()
tarayici.setModelTypeAsTinyYOLOv3()
tarayici.setModelPath('C:/Users/ahmet/Downloads/yolo-tiny.h5')
tarayici.loadModel()
tarayici.detectObjectsFromImage(input_image="C:/Users/ahmet/Desktop/Scripts[Codedbyme]/images/bike.jpg", output_image_path="bikenew.jpg", minimum_percentage_probability=30)