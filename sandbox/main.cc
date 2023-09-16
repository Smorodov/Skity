#include <skity/skity.hpp>

#include "gl/gl_app.hpp"
#include "perf.hpp"

void render_frame(skity::Canvas* canvas,
                  std::shared_ptr<skity::Typeface> const& typeface,
                  std::shared_ptr<skity::Typeface> const& emoji, float mx,
                  float my, float width, float height, float t);

class GLFrameApp : public example::GLApp {
 public:
  GLFrameApp()
      : example::GLApp(1000, 600, u8"Пример", {0.3f, 0.3f, 0.32f, 1.f}),
        fpsGraph(Perf::GRAPH_RENDER_FPS, u8"Кадров/сек.:"),
        cpuGraph(Perf::GRAPH_RENDER_MS, u8"Время CPU :") {}
  ~GLFrameApp() override = default;

 protected:
  void OnStart() override {
    typeface_ = skity::Typeface::MakeFromFile("Resources/Roboto-Regular.ttf");
    emoji_typeface_ =
        skity::Typeface::MakeFromFile("Resources/NotoEmoji-Regular.ttf");
    time_ = prev_time_ = glfwGetTime();
  }

  void OnUpdate(float elapsed_time) override {
    double mx, my;
    GetCursorPos(mx, my);
    time_ = glfwGetTime();
    double dt = time_ - prev_time_;
    prev_time_ = time_;
    render_frame(GetCanvas(), typeface_, emoji_typeface_, mx, my, ScreenWidth(),
                 ScreenHeight(), time_);
    cpu_time_ = glfwGetTime() - time_;
    fpsGraph.RenderGraph(GetCanvas(), 5, 0);
    cpuGraph.RenderGraph(GetCanvas(), 5, 35);
    GetCanvas()->flush();
    fpsGraph.UpdateGraph(dt);
    cpuGraph.UpdateGraph(cpu_time_);
  }

 private:
  std::shared_ptr<skity::Typeface> typeface_ = {};
  std::shared_ptr<skity::Typeface> emoji_typeface_ = {};
  double time_ = 0;
  double prev_time_ = 0;
  double cpu_time_ = 0;
  double dt_ = 0;
  Perf fpsGraph;
  Perf cpuGraph;
};

int main(int argc, const char** argv) {
  GLFrameApp app;
  app.Run();
  return 0;
}
