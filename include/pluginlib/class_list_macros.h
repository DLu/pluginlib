/*********************************************************************
*
* Software License Agreement (BSD License)
*
*  Copyright (c) 2008, Willow Garage, Inc.
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   * Redistributions in binary form must reproduce the above
*     copyright notice, this list of conditions and the following
*     disclaimer in the documentation and/or other materials provided
*     with the distribution.
*   * Neither the name of Willow Garage, Inc. nor the names of its
*     contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
*  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
*  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
*  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*
*********************************************************************/

#ifndef PLUGINLIB_CLASS_LIST_MACROS_H_
#define PLUGINLIB_CLASS_LIST_MACROS_H_

//include "Poco/ClassLibrary.h"
#include <plugins.h> 

inline __attribute__((deprecated)) void PLUGINLIB_REGISTER_CLASS (){
// "You are using a deprecated version of the PLUGINLIB_REGISTER_CLASS macro. Please switch to the new version PLUGINLIB_DECLARE_CLASS. For further information, see http://ros.org/wiki/pluginlib"
  return;
};

#define PLUGINLIB_REGISTER_CLASS(class_name, class_type, base_class_type) \
  POCO_BEGIN_NAMED_MANIFEST(class_name, base_class_type) \
  POCO_EXPORT_CLASS(class_type) \
  PLUGINLIB_REGISTER_CLASS();   \
  POCO_END_MANIFEST             

/*
#define PLUGINLIB_DECLARE_CLASS(pkg, class_name, class_type, base_class_type) \
  POCO_BEGIN_NAMED_MANIFEST(pkg##__##class_name, base_class_type) \
  POCO_EXPORT_CLASS(class_type) \
  POCO_END_MANIFEST
*/

#define PLUGINLIB_DECLARE_CLASS(pkg, class_name, class_type, base_class_type) \
  PLUGINS_REGISTER_CLASS(class_type, base_class_type)

#endif
