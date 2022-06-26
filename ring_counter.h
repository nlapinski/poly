#include <imgui_internal.h>



void RingCounter(unsigned int segs, long long unsigned step, unsigned int div)
{

        ImVec2 vMax = ImGui::GetWindowContentRegionMax();        
        const float RADIUS = 90.0f;

        int num_segments = 32;

        static ImVec4 colA = ImVec4(0.0f, 0.9f, 0.9f, 1.0f);
        static ImVec4 colB = ImVec4(0.89f, 0.0f, 0.89f, 1.0f);
        static ImVec4 colC = ImVec4(0.29f, 0.0f, 0.29f, 1.0f);
        static ImVec4 colD = ImVec4(0.20f, 0.29f, 0.6f, 1.0f);
        ImVec2 center  = ImVec2(ImGui::GetWindowPos().x+(vMax.x/2),ImGui::GetWindowPos().y+(vMax.y/2));
        //ImGui::GetForegroundDrawList()->AddCircle(center, RADIUS, ImColor(col), 80.0f, 3.0f);
        ImDrawList* draw_list = ImGui::GetForegroundDrawList();
        draw_list->PushClipRectFullScreen();
        //_pie(center, RADIUS, col, 32);
        float wedge_angle = ((float)IM_PI*2.0) / (float)(segs);

        float div_pad = (IM_PI/1.5)/(float)segs;

        for(unsigned int i = 0;i<segs;i++){
            
            float a_min = (i*wedge_angle)-div_pad;
            float a_max = ((i)*wedge_angle)+div_pad;
            draw_list->PathArcTo(center, (float)RADIUS, a_min, a_max, num_segments);
            if(step%segs==(i)){
                if(i % div==0){
                    draw_list->PathStroke(ImColor(colA),0,8.5f);
                    //trig = 1;        
                }
                else{
                    draw_list->PathStroke(ImColor(colD),0,6.5f);        
                }
                
                
            }
            else{
                if(i % div==0){
                    draw_list->PathStroke(ImColor(colB),0,3.5f);
                }
                else{
                    draw_list->PathStroke(ImColor(colC),0,2.5f);   
                }
            }
            
        }

        draw_list->PopClipRect();
}