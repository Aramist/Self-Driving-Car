;; Auto-generated. Do not edit!


(when (boundp 'cartographer_ros_msgs::WriteAssets)
  (if (not (find-package "CARTOGRAPHER_ROS_MSGS"))
    (make-package "CARTOGRAPHER_ROS_MSGS"))
  (shadow 'WriteAssets (find-package "CARTOGRAPHER_ROS_MSGS")))
(unless (find-package "CARTOGRAPHER_ROS_MSGS::WRITEASSETS")
  (make-package "CARTOGRAPHER_ROS_MSGS::WRITEASSETS"))
(unless (find-package "CARTOGRAPHER_ROS_MSGS::WRITEASSETSREQUEST")
  (make-package "CARTOGRAPHER_ROS_MSGS::WRITEASSETSREQUEST"))
(unless (find-package "CARTOGRAPHER_ROS_MSGS::WRITEASSETSRESPONSE")
  (make-package "CARTOGRAPHER_ROS_MSGS::WRITEASSETSRESPONSE"))

(in-package "ROS")





(defclass cartographer_ros_msgs::WriteAssetsRequest
  :super ros::object
  :slots (_stem ))

(defmethod cartographer_ros_msgs::WriteAssetsRequest
  (:init
   (&key
    ((:stem __stem) "")
    )
   (send-super :init)
   (setq _stem (string __stem))
   self)
  (:stem
   (&optional __stem)
   (if __stem (setq _stem __stem)) _stem)
  (:serialization-length
   ()
   (+
    ;; string _stem
    4 (length _stem)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _stem
       (write-long (length _stem) s) (princ _stem s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _stem
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _stem (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass cartographer_ros_msgs::WriteAssetsResponse
  :super ros::object
  :slots ())

(defmethod cartographer_ros_msgs::WriteAssetsResponse
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass cartographer_ros_msgs::WriteAssets
  :super ros::object
  :slots ())

(setf (get cartographer_ros_msgs::WriteAssets :md5sum-) "1ca78fe806c5256bb03c4e35886127f9")
(setf (get cartographer_ros_msgs::WriteAssets :datatype-) "cartographer_ros_msgs/WriteAssets")
(setf (get cartographer_ros_msgs::WriteAssets :request) cartographer_ros_msgs::WriteAssetsRequest)
(setf (get cartographer_ros_msgs::WriteAssets :response) cartographer_ros_msgs::WriteAssetsResponse)

(defmethod cartographer_ros_msgs::WriteAssetsRequest
  (:response () (instance cartographer_ros_msgs::WriteAssetsResponse :init)))

(setf (get cartographer_ros_msgs::WriteAssetsRequest :md5sum-) "1ca78fe806c5256bb03c4e35886127f9")
(setf (get cartographer_ros_msgs::WriteAssetsRequest :datatype-) "cartographer_ros_msgs/WriteAssetsRequest")
(setf (get cartographer_ros_msgs::WriteAssetsRequest :definition-)
      "













string stem
---

")

(setf (get cartographer_ros_msgs::WriteAssetsResponse :md5sum-) "1ca78fe806c5256bb03c4e35886127f9")
(setf (get cartographer_ros_msgs::WriteAssetsResponse :datatype-) "cartographer_ros_msgs/WriteAssetsResponse")
(setf (get cartographer_ros_msgs::WriteAssetsResponse :definition-)
      "













string stem
---

")



(provide :cartographer_ros_msgs/WriteAssets "1ca78fe806c5256bb03c4e35886127f9")


