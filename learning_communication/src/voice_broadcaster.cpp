#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <geometry_msgs/Twist.h>
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"

ros::Publisher robot_vel;
void voiceCallback1(const std_msgs::String::ConstPtr& msg)
{
    ros::NodeHandle node;
    robot_vel=node.advertise<geometry_msgs::Twist>("/cmd_vel",10);
    ros::Rate rate(10);
    
    //发布速度指令
    if (msg->data == "向左。")
    {
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.x=2;
        robot_vel.publish(vel_msg);
        ros::spinOnce();
        rate.sleep();
    }
    if (msg->data == "向右。")
    {
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.x=-2;
        robot_vel.publish(vel_msg);
        ros::spinOnce();
        rate.sleep();
    }
    if (msg->data == "向前。")
    {
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.y=2;
        robot_vel.publish(vel_msg);
        ros::spinOnce();
        rate.sleep();
    }    
    if (msg->data == "向后。")
    {
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.y=-2;
        robot_vel.publish(vel_msg);
        ros::spinOnce();
        rate.sleep();
    }   
    // ROS_INFO("I heard: NO");
 
}




int main(int argc, char** argv)
{
    // 初始化节点
    ros::init(argc, argv, "voice_broadcaster");
    ros::NodeHandle node;
 

    ros::Subscriber sub1 = node.subscribe("voiceWords", 1000,  &voiceCallback1);



    // robot_vel=node.advertise<geometry_msgs::Twist>("/cmd_vel",10);
    // ros::Rate rate(10);

    // while (node.ok())
    // {
    //     geometry_msgs::Twist vel_msg;
    //     vel_msg.angular.z=-2;
    //     vel_msg.linear.x=2;
    //     robot_vel.publish(vel_msg);
    //     ros::spinOnce();
    //     rate.sleep();
    // }
    return 0;
};
