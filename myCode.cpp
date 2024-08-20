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
//    ImFont* font2 = io.Fonts->AddFontFromFileTTF("/Users/reubenjarvela/Library/Fonts/Arial Unicode.ttf", 23.0f, NULL, io.Fonts->GetGlyphRangesDefault());
//    
    
    
    static float distance = 0.00;
    static float time = 0.00;
    static float pace = 0.00;
    
    ImGui::Begin("Run Tracker");
    
    ImGui::Text("Add details of your run:");
    
    ImGui::Text("Distance "); ImGui::SameLine();
    // manually dictate width of float input line
    ImGui::PushItemWidth(60);
    // below shows float input, with text, step basic, step fast then floating point value
    ImGui::InputFloat("(km)", &distance, 0.0f, 0.0f, "%.2f");
    
    
    ImGui::PushItemWidth(60);
    ImGui::Text("Time \t"); ImGui::SameLine();
    ImGui::InputFloat("(min)", &time, 0.0f, 0.0f, "%.2f");
    
    ImGui::PushItemWidth(60);
    ImGui::Text("Pace \t"); ImGui::SameLine();
    ImGui::InputFloat("(min/km)", &pace, 0.0f, 0.0f, "%.2f");
  
    
    
    ImGui::End();
   
   

}
}
