// dear imgui app: standalone application starter kit

#include "imgui_app.h"
#include "imgui_internal.h"

#include "imgui.h"
#include "imgui_impl_opengl3.h"

#include "imgui_app_opengl_loader.h"

namespace ImGuiApp
{

bool InitRenderer()
{
    // Setup Renderer bindings
    return ImGui_ImplOpenGL3_Init(IMGUI_APP_GLSL_VERSION);
}

void BeginFrameRenderer()
{
    ImGui_ImplOpenGL3_NewFrame();
}

void EndFrameRenderer(const ImVec4 &clear_col = ImVec4(0, 0, 0, 1.f))
{
    auto &io = ImGui::GetIO();
    glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
    glClearColor(clear_col.x, clear_col.y, clear_col.z, clear_col.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void CleanupRenderer()
{
    ImGui_ImplOpenGL3_Shutdown();
}

}
