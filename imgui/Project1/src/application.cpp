#include<GL/glew.h>
#include <GLFW/glfw3.h>
#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_impl_glfw_gl3.h"
#include <iostream>
int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Pinche atracion", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);


    if(glewInit() != GLEW_OK)
    {
        std::cout << "Error !" << std::endl;
    }

   /* unsigned int a;
    glGenBuffers(1, &a);*/

    std::cout << glGetString(GL_VERSION) << std::endl;

    // Init GUI

    // Setup ImGui binding
    ImGui::CreateContext();
    ImGui_ImplGlfwGL3_Init(window, true);
    ImGui::StyleColorsDark();

    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    const char* seasons[4] = { "Invierno", "Verano",
                             "Otoño", "Primavera" };

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {

        // GUI NEW FRAME
        ImGui_ImplGlfwGL3_NewFrame();


        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();




        // 1. Show a simple window.
        // Tip: if we don't call ImGui::Begin()/ImGui::End() the widgets automatically appears in a window called "Debug".
        {
            static float f = 0.0f;
            static int numSeason= 1;
            ImGui::Text("Pinche VGI!");                           // Display some text (you can use a format string too)
            ImGui::SliderFloat("Velocidad", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f    
            ImGui::SliderFloat3("Mover camara", &f ,0.0f, 960.0f); // Edit 3 floats representing a color

         
            ImGui::Checkbox("Dividir pantalla", &show_another_window);
            
            // no se como pitos declararlos con un for y lanzarlos con un swith o algo asi

            if (ImGui::Button(seasons[0]))                          // Buttons return true when clicked (NB: most widgets return true when edited/activated)
                numSeason = 0;
            if (ImGui::Button(seasons[1]))
                numSeason = 1;
            if (ImGui::Button(seasons[2]))
                numSeason = 2;
            if (ImGui::Button(seasons[3]))
                numSeason = 3;



            //ImGui::SameLine();
            //ImGui::Text("Estación actual", seasons[numSeason]);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        }


        // GUI 
        ImGui::Render();
        ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    // GUI clean
    ImGui_ImplGlfwGL3_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();
    return 0;
}