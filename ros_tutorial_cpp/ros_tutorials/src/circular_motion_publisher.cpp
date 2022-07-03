#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <ros_tutorials/TurtleMsg.h>
#include <math.h>

class CircularMotionPublisher
{
public:

    CircularMotionPublisher():loop_rate(10) //loop_rate 10Hz로 설정
    {
        publisher_ = nh.advertise<geometry_msgs::Twist>("/robot1/turtle1/cmd_vel",10);
        subscriber_ = nh.subscribe("/robot1/circular_motion",10,&CircularMotionPublisher::msgCallback, this);
    }

    void msgCallback(const ros_tutorials::TurtleMsg::ConstPtr& msg)
    {
        float r = msg->radius;
        float v = msg->velocity;

        twist.linear.x= v;
        twist.linear.y=0.0;
        twist.linear.z=0.0;

        twist.angular.x=0.0;
        twist.angular.y=0.0;
        twist.angular.z= v/r;
    }


    // loop_rate에 맞게 저장된 Twist 메시지를 Publish하도록 spin 설정
    void spin()
    {
        while(ros::ok())
        {
            publisher_.publish(twist);
            ros::spinOnce();
            loop_rate.sleep();
        }
    }

private:
    //nodehandle과 Publisher, Subscriber, 속도 정보를 저장할 Twist 메시지 객체 생성
    ros::NodeHandle nh;
    ros::Publisher publisher_;
    ros::Subscriber subscriber_;
    ros::Rate loop_rate;
    geometry_msgs::Twist twist;
};


int main(int argc, char **argv)
{
    //ROS 시작 후 객체 생성 및 spin
    ros::init(argc, argv, "cm_publisher");
    CircularMotionPublisher cm_publisher;
    cm_publisher.spin();
    return 0;
}
