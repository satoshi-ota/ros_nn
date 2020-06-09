#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <torch/script.h>

class PytorchTEST{
public:
  PytorchTEST();
  void process();
private:
  ros::NodeHandle nh;
  ros::Publisher vel_pub;
  torch::jit::script::Module module;
};

PytorchTEST::PytorchTEST(){
  vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
  // module = torch::jit::load("model.pt");
}

void PytorchTEST::process(){
  // ros::Rate loop_rate(10);
  // geometry_msgs::Twist vel;
  // while(ros::ok()){
  //   torch::Tensor input = torch::ones({1, 3, 64, 64});
  //   auto output = module.forward({input}).toTensor();
  //   vel.linear.x = output[0].item<float>();
  //   vel.angular.z = output[1].item<float>();
  //   vel_pub.publish(vel);
  //   loop_rate.sleep();
  //   ros::spinOnce();
  // }
}

int main(int argc, char** argv){
  ros::init(argc, argv, "pytorch_test");
  PytorchTEST pytorch_test;
  // pytorch_test.process();
  torch::Tensor tensor = torch::rand({2, 3});
  std::cout << tensor << std::endl;
  ros::spin();
  return 0;
}
