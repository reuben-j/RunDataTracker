//
//  myCode.cpp
//  example_osx_opengl2
//
//  Created by Reuben Jarvela on 20/08/2024.
//  Copyright © 2024 ImGui. All rights reserved.
//
#include <iostream>
#include <iomanip>
#include "myCode.hpp"
#include "imgui.h"

using namespace std;

namespace myCode {

void renderMainWindow() {
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    
    static float vec101[3] = {5.0f, 30.0f, 4};
    static int runCount = 0;
    
    
    ImGui::Begin("Run Tracker");
    
    ImGui::Text("Add details of your run:");
    ImGui::PushItemWidth(80);
   
    ImGui::Text("Run Count"); ImGui::SameLine();
    ImGui::InputInt(" ", &runCount, 1);
    
    ImGui::Text("Distance "); ImGui::SameLine();
    // manually dictate width of float input line
    
    // below shows float input, with text, step basic, step fast then floating point value
    ImGui::InputFloat("(km)", &vec101[0], 0.0f, 0.0f, "%.2f");
    
    
   
    ImGui::Text("Time \t"); ImGui::SameLine();
    ImGui::InputFloat("(min)", &vec101[1], 0.0f, 0.0f, "%.2f");
    
   
    ImGui::Text("Pace \t"); ImGui::SameLine();
    ImGui::InputFloat("(min/km)", &vec101[2], 0.0f, 0.0f, "%.2f");
    ImGui::PushItemWidth(100);
    static int item_type = 3;
    const char* item_names[] =
    {
        "Casual", "Easy", "Medium", "Hard", "Brutal"
    };
    ImGui::Text("Effort   "); ImGui::SameLine();
    ImGui::Combo("##", &item_type, item_names, IM_ARRAYSIZE(item_names), IM_ARRAYSIZE(item_names));
    ImGui::Indent(150);
    
    ImGui::Button("Add");
    
    ImGui::End();
   
   

}
}
