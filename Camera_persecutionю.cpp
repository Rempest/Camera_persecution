#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>
using namespace std;
using namespace cv;

class Camera_persecution {
     private:
       Ptr<Tracker> tracker;
       Rect2d bbox;
       bool isInitialized;
Oblect_tracker(){
       tracker = TrackerCSRT::create();
       isInitialized = false;
}
void init(math& frame){
  bbox = selectROI("Choice the object: ", frame);
  tracker->init(frame, bbox);
  isInitialized = true;
  }
bool update(math& frame){
  if (!isInitialized) return false;
  return tracker->update(frame, bbox);
}
void draw(Math, frame){
  if(isInitialized == true){
    rectangle(frame, bbox, Scalar(0, 255, 0), 2);
  }
}
 Rect2d getBBox() const {
        return bbox;
    }
};
class Camera_syste(){};
