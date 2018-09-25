#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <geometry_msgs/Twist.h>
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"

ros::Publisher robot_vel;
void poseCallback1(const std_msgs::Int32::ConstPtr& msg)
{
    ros::NodeHandle node;
    robot_vel=node.advertise<geometry_msgs::Twist>("/cmd_vel",10);
    ros::Rate rate(10);
    
    //发布速度指令
    if (msg->data <150)
    {
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.x=2;
        robot_vel.publish(vel_msg);
        ros::spinOnce();
        rate.sleep();
    }
    else
    {
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.x=-2;
        robot_vel.publish(vel_msg);
        ros::spinOnce();
        rate.sleep();
    }
    
    // ROS_INFO("I heard: NO");
 
}

void poseCallback2(const std_msgs::Int32::ConstPtr& msg)
{
    ros::NodeHandle node;
    robot_vel=node.advertise<geometry_msgs::Twist>("/cmd_vel",10);
    ros::Rate rate(10);
    
    //发布速度指令
    if (msg->data >150)
    {
        geometry_msgs::Twist vel_msg;
        vel_msg.angular.z=-2;
        robot_vel.publish(vel_msg);
        ros::spinOnce();
        rate.sleep();
    }
    else
    {
        geometry_msgs::Twist vel_msg;
        vel_msg.angular.z=2;
        robot_vel.publish(vel_msg);
        ros::spinOnce();
        rate.sleep();
    }
    
    // ROS_INFO("I heard: NO");
 
}

void poseCallback3(const std_msgs::Int32::ConstPtr& msg)
{
    ros::NodeHandle node;
    robot_vel=node.advertise<geometry_msgs::Twist>("/cmd_vel",10);
    ros::Rate rate(10);
    
    //发布速度指令
    if (msg->data >200)
    {
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.y=-2;
        robot_vel.publish(vel_msg);
        ros::spinOnce();
        rate.sleep();
    }
    else
    {
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.y=2;
        robot_vel.publish(vel_msg);
        ros::spinOnce();
        rate.sleep();
    }
    
    // ROS_INFO("I heard: NO");
 
}

// void poseCallback4(const std_msgs::Int32::ConstPtr& msg)
// {
//     ros::NodeHandle node;
//     robot_vel=node.advertise<geometry_msgs::Twist>("/cmd_vel",10);
//     ros::Rate rate(10);
    
//     //发布速度指令
//     if (msg->data >150)
//     {
//         geometry_msgs::Twist vel_msg;
//         vel_msg.angular.z=-2;
//         vel_msg.linear.x=2;
//         robot_vel.publish(vel_msg);
//         ros::spinOnce();
//         rate.sleep();
//     }
    
//     // ROS_INFO("I heard: NO");
 
// }

int main(int argc, char** argv)
{
    // 初始化节点
    ros::init(argc, argv, "usb_broadcaster");
    ros::NodeHandle node;
 

    ros::Subscriber sub1 = node.subscribe("a", 10,  &poseCallback1);
    ros::Subscriber sub2 = node.subscribe("y", 10,  &poseCallback2);
    ros::Subscriber sub3 = node.subscribe("w", 10,  &poseCallback3);    
    // ros::Subscriber sub4 = node.subscribe("h", 10,  &poseCallback4); 


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
