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

static void PushStyleCompact()
{
    ImGuiStyle& style = ImGui::GetStyle();
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(style.FramePadding.x, (float)(int)(style.FramePadding.y * 0.60f)));
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(style.ItemSpacing.x, (float)(int)(style.ItemSpacing.y * 0.60f)));
}

static void PopStyleCompact()
{
    ImGui::PopStyleVar(2);
}

void renderMainWindow() {
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    
    static float vec101[4] = {5.0f, 30.0f, 4, 0.0};
    static int runCount = 0;
    static int tableCount = 0;
    static int num1 = 0;
    
    
    
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
    if(ImGui::Button("Add to table")) {
        num1++;
    };
    
    ImGui::SetNextItemWidth(200);
    
    if (ImGui::BeginTable("table3", 3))
    {
        for (int item = 0; item < num1; item++)
        {
            ImGui::TableNextColumn();
            ImGui::Text("Run: #%d\n%0.2fkm\n%0.2fmin\n%0.2fmin/km\nEffort: %s", runCount, vec101[0], vec101[1], vec101[2], *item_names);
        }
        ImGui::EndTable();
    }
    
    // [Method 2] Using TableNextColumn() called multiple times, instead of using a for loop + TableSetColumnIndex().
    // This is generally more convenient when you have code manually submitting the contents of each column.
    
    ImGui::End();
    
    
    
}
void renderSecondWindow() {
    
    ImGui::Begin("Second Window!");
    
    static int runCount = 1;
    static int addToTable = 1;
    static float distArr[100];
    static float timeArr[100];
    static float paceArr[100];
    static int effortArr[100];
    
    
    ImGui::PushItemWidth(100);
    ImGui::Text("Run Count"); ImGui::SameLine();
    ImGui::InputInt("##", &runCount);
    
    ImGui::Text("Distance "); ImGui::SameLine();
    ImGui::InputFloat("km", &distArr[runCount], 0.0f, 0.0f, "%.2f");
    
    ImGui::Text("Time\t "); ImGui::SameLine();
    ImGui::InputFloat("min", &timeArr[runCount], 0.0f, 0.0f, "%.2f");
    
    ImGui::Text("Pace\t "); ImGui::SameLine();
    ImGui::InputFloat("min/km", &paceArr[runCount], 0.0f, 0.0f, "%.2f");
    
    static ImGuiTableFlags flags = ImGuiTableFlags_ScrollY | ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV | ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable;

    PushStyleCompact();
    ImGui::CheckboxFlags("ImGuiTableFlags_ScrollY", &flags, ImGuiTableFlags_ScrollY);
    PopStyleCompact();

    
    const float TEXT_BASE_HEIGHT = ImGui::GetTextLineHeightWithSpacing();
    
    // When using ScrollX or ScrollY we need to specify a size for our table container!
    // Otherwise by default the table will fit all available space, like a BeginChild() call.
    ImVec2 outer_size = ImVec2(0.0f, TEXT_BASE_HEIGHT * 8);
    if (ImGui::BeginTable("table_scrolly", 3, flags, outer_size))
    {
        ImGui::TableSetupScrollFreeze(0, 1); // Make top row always visible
        ImGui::TableSetupColumn("One", ImGuiTableColumnFlags_None);
        ImGui::TableSetupColumn("Two", ImGuiTableColumnFlags_None);
        ImGui::TableSetupColumn("Three", ImGuiTableColumnFlags_None);
        ImGui::TableHeadersRow();

        // Demonstrate using clipper for large vertical lists
        ImGuiListClipper clipper;
        clipper.Begin(1000);
        while (clipper.Step())
        {
            for (int row = clipper.DisplayStart; row < clipper.DisplayEnd; row++)
            {
                ImGui::TableNextRow();
                for (int column = 0; column < 3; column++)
                {
                    ImGui::TableSetColumnIndex(column);
                    ImGui::Text("Hello %d,%d", column, row);
                }
            }
        }
        ImGui::EndTable();
    }
        
    ImGui::End();
}

void lightDarkSwitch() {
    ImGui::Begin("Settings");
    ImGui::PushItemWidth(250);
    static int styleInt = -1;
    if(ImGui::Combo("Style Selector", &styleInt, "Dark\0Light\0Classic\0")) {
        switch (styleInt) {
            case 0: ImGui::StyleColorsDark(); break;
            case 1: ImGui::StyleColorsLight(); break;
            case 2: ImGui::StyleColorsClassic(); break;
            default: ImGui::StyleColorsDark(); break;
        }
    }
    ImGui::End();
}

}
