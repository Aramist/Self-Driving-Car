; Auto-generated. Do not edit!


(cl:in-package cartographer_ros_msgs-srv)


;//! \htmlinclude WriteAssets-request.msg.html

(cl:defclass <WriteAssets-request> (roslisp-msg-protocol:ros-message)
  ((stem
    :reader stem
    :initarg :stem
    :type cl:string
    :initform ""))
)

(cl:defclass WriteAssets-request (<WriteAssets-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <WriteAssets-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'WriteAssets-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name cartographer_ros_msgs-srv:<WriteAssets-request> is deprecated: use cartographer_ros_msgs-srv:WriteAssets-request instead.")))

(cl:ensure-generic-function 'stem-val :lambda-list '(m))
(cl:defmethod stem-val ((m <WriteAssets-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader cartographer_ros_msgs-srv:stem-val is deprecated.  Use cartographer_ros_msgs-srv:stem instead.")
  (stem m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <WriteAssets-request>) ostream)
  "Serializes a message object of type '<WriteAssets-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'stem))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'stem))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <WriteAssets-request>) istream)
  "Deserializes a message object of type '<WriteAssets-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'stem) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'stem) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<WriteAssets-request>)))
  "Returns string type for a service object of type '<WriteAssets-request>"
  "cartographer_ros_msgs/WriteAssetsRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'WriteAssets-request)))
  "Returns string type for a service object of type 'WriteAssets-request"
  "cartographer_ros_msgs/WriteAssetsRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<WriteAssets-request>)))
  "Returns md5sum for a message object of type '<WriteAssets-request>"
  "1ca78fe806c5256bb03c4e35886127f9")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'WriteAssets-request)))
  "Returns md5sum for a message object of type 'WriteAssets-request"
  "1ca78fe806c5256bb03c4e35886127f9")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<WriteAssets-request>)))
  "Returns full string definition for message of type '<WriteAssets-request>"
  (cl:format cl:nil "~%~%~%~%~%~%~%~%~%~%~%~%~%~%string stem~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'WriteAssets-request)))
  "Returns full string definition for message of type 'WriteAssets-request"
  (cl:format cl:nil "~%~%~%~%~%~%~%~%~%~%~%~%~%~%string stem~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <WriteAssets-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'stem))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <WriteAssets-request>))
  "Converts a ROS message object to a list"
  (cl:list 'WriteAssets-request
    (cl:cons ':stem (stem msg))
))
;//! \htmlinclude WriteAssets-response.msg.html

(cl:defclass <WriteAssets-response> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass WriteAssets-response (<WriteAssets-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <WriteAssets-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'WriteAssets-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name cartographer_ros_msgs-srv:<WriteAssets-response> is deprecated: use cartographer_ros_msgs-srv:WriteAssets-response instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <WriteAssets-response>) ostream)
  "Serializes a message object of type '<WriteAssets-response>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <WriteAssets-response>) istream)
  "Deserializes a message object of type '<WriteAssets-response>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<WriteAssets-response>)))
  "Returns string type for a service object of type '<WriteAssets-response>"
  "cartographer_ros_msgs/WriteAssetsResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'WriteAssets-response)))
  "Returns string type for a service object of type 'WriteAssets-response"
  "cartographer_ros_msgs/WriteAssetsResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<WriteAssets-response>)))
  "Returns md5sum for a message object of type '<WriteAssets-response>"
  "1ca78fe806c5256bb03c4e35886127f9")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'WriteAssets-response)))
  "Returns md5sum for a message object of type 'WriteAssets-response"
  "1ca78fe806c5256bb03c4e35886127f9")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<WriteAssets-response>)))
  "Returns full string definition for message of type '<WriteAssets-response>"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'WriteAssets-response)))
  "Returns full string definition for message of type 'WriteAssets-response"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <WriteAssets-response>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <WriteAssets-response>))
  "Converts a ROS message object to a list"
  (cl:list 'WriteAssets-response
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'WriteAssets)))
  'WriteAssets-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'WriteAssets)))
  'WriteAssets-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'WriteAssets)))
  "Returns string type for a service object of type '<WriteAssets>"
  "cartographer_ros_msgs/WriteAssets")