
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <skity/skity.hpp>
#include <string>
#include "entypo.h"

// same as https://fiddle.skia.org/c/@shapes
static void draw_basic_example(skity::Canvas* canvas) {
  skity::Paint paint;
  paint.setStyle(skity::Paint::kFill_Style);
  paint.setAntiAlias(true);
  paint.setStrokeWidth(4.f);
  paint.setFillColor(0x42 / 255.f, 0x85 / 255.f, 0xF4 / 255.f, 1.f);

  skity::Rect rect = skity::Rect::MakeXYWH(10, 10, 100, 160);
  canvas->drawRect(rect, paint);

  skity::RRect oval;
  oval.setOval(rect);
  oval.offset(40, 80);
  paint.setFillColor(0xDB / 255.f, 0x44 / 255.f, 0x37 / 255.f, 1.f);
  canvas->drawRRect(oval, paint);

  paint.setFillColor(0x0F / 255.f, 0x9D / 255.f, 0x58 / 255.f, 1.f);
  canvas->drawCircle(180, 50, 25, paint);

  rect.offset(80, 50);
  paint.setStrokeColor(0xF4 / 255.f, 0xB4 / 255.f, 0x0, 1.f);
  paint.setStyle(skity::Paint::kStroke_Style);
  canvas->drawRoundRect(rect, 10, 10, paint);
}

// same as https://fiddle.skia.org/c/@discrete_path
static void draw_path_effect_example(skity::Canvas* canvas) {
  const float R = 115.2f, C = 128.f;
  skity::Path path;
  path.moveTo(C + R, C);
  for (int32_t i = 1; i < 8; i++) {
    float a = 2.6927937f * i;
    path.lineTo(C + R * std::cos(a), C + R * std::sin(a));
  }

  skity::Paint paint;
  paint.setPathEffect(skity::PathEffect::MakeDiscretePathEffect(10.f, 4.f));
  paint.setStyle(skity::Paint::kStroke_Style);
  paint.setStrokeWidth(2.f);
  paint.setAntiAlias(true);
  paint.setStrokeColor(0x42 / 255.f, 0x85 / 255.f, 0xF4 / 255.f, 1.f);
  canvas->drawPath(path, paint);
}

static void draw_dash_start_example(skity::Canvas* canvas) {
  skity::Path path;
  path.moveTo(199, 34);
  path.lineTo(253, 143);
  path.lineTo(374, 160);
  path.lineTo(287, 244);
  path.lineTo(307, 365);
  path.lineTo(199, 309);
  path.lineTo(97, 365);
  path.lineTo(112, 245);
  path.lineTo(26, 161);
  path.lineTo(146, 143);
  path.close();

  skity::Paint paint;
  paint.setStrokeWidth(3.f);
  paint.setStrokeJoin(skity::Paint::kRound_Join);
  paint.setStrokeCap(skity::Paint::kRound_Cap);
  paint.setStrokeColor(0, 0, 1, 1);
  paint.setFillColor(150.f / 255.f, 150.f / 255.f, 1.f, 1.f);
  paint.setAntiAlias(true);
  paint.setStyle(skity::Paint::kStrokeAndFill_Style);
  float pattern[2] = {10.f, 10.f};
  paint.setPathEffect(skity::PathEffect::MakeDashPathEffect(pattern, 2, 0));

  canvas->drawPath(path, paint);
}

// same as https://fiddle.skia.org/c/844ab7d5e63876f6c889b33662ece8d5
void draw_linear_gradient_example(skity::Canvas* canvas) {
  skity::Paint p;
  p.setStyle(skity::Paint::kFill_Style);

  skity::Vec4 colors[] = {
      skity::Vec4{0.f, 1.f, 1.f, 0.f},
      skity::Vec4{0.f, 0.f, 1.f, 1.f},
      skity::Vec4{1.f, 0.f, 0.f, 1.f},
  };
  float positions[] = {0.f, 0.65f, 1.f};

  for (int i = 0; i < 4; i++) {
    float blockX = (i % 2) * 100.f;
    float blockY = (i / 2) * 100.f;

    std::vector<skity::Point> pts = {
        skity::Point{blockX, blockY, 0.f, 1.f},
        skity::Point{blockX + 50, blockY + 100, 0.f, 1.f},
    };

    skity::Matrix matrix = glm::identity<skity::Matrix>();
    int flag = 0;
    if (i % 2 == 1) {
      flag = 1;
    }
    if (i / 2 == 1) {
      matrix *= glm::translate(glm::identity<glm::mat4>(),
                               glm::vec3(blockX, blockY, 0));
      matrix *= glm::rotate(glm::identity<glm::mat4>(), glm::radians(45.f),
                            glm::vec3(0, 0, 1));
      matrix *= glm::translate(glm::identity<glm::mat4>(),
                               glm::vec3(-blockX, -blockY, 0));
    }
    auto lgs =
        skity::Shader::MakeLinear(pts.data(), colors, positions, 3, flag);
    lgs->SetLocalMatrix(matrix);
    p.setShader(lgs);
    auto r = skity::Rect::MakeLTRB(blockX, blockY, blockX + 100, blockY + 100);
    canvas->drawRect(r, p);
  }

  skity::Path circle;
  circle.addCircle(220, 350, 100);
  skity::Paint paint;
  paint.setStyle(skity::Paint::kFill_Style);
  paint.setAntiAlias(true);
  skity::Point center{220, 350, 0, 1};
  skity::Vec4 radialColors[] = {skity::Vec4{1.f, 1.f, 1.f, 1.f},
                                skity::Vec4{0.f, 0.f, 0.f, 1.f}};
  float pts[] = {0.f, 1.f};
  auto rgs = skity::Shader::MakeRadial(center, 150.f, radialColors, nullptr, 2);
  paint.setShader(rgs);

  canvas->drawPath(circle, paint);
}

// same as https://fiddle.skia.org/c/@text_rendering
void draw_simple_text(skity::Canvas* canvas)
{
  skity::Paint paint;

  paint.setTextSize(64.f);
  paint.setAntiAlias(true);
  paint.setFillColor(0x42 / 255.f, 0x85 / 255.f, 0xF4 / 255.f, 1.f);
  paint.setStyle(skity::Paint::kFill_Style);

  skity::TextBlobBuilder builder;
  paint.setTypeface(canvas->getDefaultTypeface());
  auto blob = builder.buildTextBlob("Skity", paint);

  canvas->drawTextBlob(blob.get(), 20.f, 64.f, paint);

  paint.setStyle(skity::Paint::kStroke_Style);
  paint.setStrokeColor(0xDB / 255.f, 0x44 / 255.f, 0x37 / 255.f, 1.f);
  paint.setStrokeWidth(2.f);

  canvas->drawTextBlob(blob.get(), 20.f, 144.f, paint);

  paint.setFillColor(0x0F / 255.f, 0x9D / 255.f, 0x58 / 255.f, 1.f);
  paint.setStyle(skity::Paint::kFill_Style);

  canvas->save();

  skity::Vec4 colors[] = {
      skity::Vec4{0.f, 1.f, 1.f, 1.f},
      skity::Vec4{0.f, 0.f, 1.f, 1.f},
      skity::Vec4{1.f, 0.f, 0.f, 1.f},
  };

  std::vector<skity::Point> pts = {
      skity::Point{0.f, 0.f, 0.f, 1.f},
      skity::Point{200.f, 0.f, 0.f, 1.f},
  };

  auto lgs = skity::Shader::MakeLinear(pts.data(), colors, nullptr, 3);
  paint.setShader(lgs);

  canvas->drawTextBlob(blob.get(), 20.f, 224.f, paint);
  canvas->restore();
}

void draw_even_odd_fill(skity::Canvas* canvas) {
  skity::Paint paint;
  paint.setStyle(skity::Paint::kFill_Style);
  paint.setColor(skity::ColorSetA(skity::Color_RED, 64));

  skity::Path path;
  path.moveTo(100, 10);
  path.lineTo(40, 180);
  path.lineTo(190, 60);
  path.lineTo(10, 60);
  path.lineTo(160, 180);
  path.close();

  canvas->drawPath(path, paint);

  canvas->save();

  canvas->translate(0, 200);

  path.setFillType(skity::Path::PathFillType::kEvenOdd);
  canvas->drawPath(path, paint);

  canvas->restore();
}
// ---------------------------------------------
//
// ---------------------------------------------
void draw_button(skity::Canvas* canvas, const char* pre_icon, const char* text,
                 float x, float y, float w, float h, skity::Color col,
                 std::shared_ptr<skity::Typeface> typeface,
                 std::shared_ptr<skity::Typeface> typeface_emoji
                 )
                 {
    float corner_radius = h*0.25f;
    float tw = 0.f, iw = 0.f;
    skity::Paint paint;
    paint.setAntiAlias(true);
    paint.setStyle(skity::Paint::kFill_Style);
    skity::RRect rrect;
    rrect.setRectXY(skity::Rect::MakeXYWH(x + 1.f, y + 1.f, w - 2.f, h - 2.f),
                    corner_radius - 1.f, corner_radius - 1.f);
    paint.setColor(col);
    canvas->drawRRect(rrect, paint);
    {
        std::array<skity::Color4f, 2> colors{};
        std::array<skity::Point, 2> pts{};
        colors[0] = skity::Color4fFromColor(skity::ColorSetARGB(32, 255, 255, 255));
        colors[1] = skity::Color4fFromColor(skity::ColorSetARGB(32, 0, 0, 0));
        pts[0] = {x, y, 0, 1};
        pts[1] = {x, y + h, 0, 1};
        paint.setShader(
                skity::Shader::MakeLinear(pts.data(), colors.data(), nullptr, 2));
    }
    canvas->drawRRect(rrect, paint);
    paint.setShader(nullptr);
    paint.setStyle(skity::Paint::kStroke_Style);
    // icon color
    paint.setColor(skity::ColorSetARGB(255, 40, 40, 255));
    rrect.setRectXY(skity::Rect::MakeXYWH(x + 0.5f, y + 0.5f, w - 1.f, h - 1.f),
                    corner_radius - 0.5f, corner_radius - 0.5f);
    canvas->drawRRect(rrect, paint);
    paint.setStyle(skity::Paint::kFill_Style);
    paint.setTextSize(h*0.8f);
    tw = canvas->simpleTextBounds(text, paint).x;


    if (pre_icon)
    {
        canvas->setDefaultTypeface(typeface_emoji);
        paint.setTextSize(h * 0.8f);
        iw = canvas->simpleTextBounds(pre_icon, paint).x;
        canvas->drawSimpleText2(pre_icon, x + w * 0.5f - tw * 0.5f - iw,y + h * 0.75f, paint);
    }
    canvas->setDefaultTypeface(typeface);
    paint.setTextSize(h*0.8f);
    paint.setColor(skity::ColorSetARGB(255, 255, 255, 255));

    canvas->drawSimpleText2(text, x + w * 0.5f - tw * 0.5f + iw * 0.25f,
                            y + h * 0.7f - 1.f, paint);
    paint.setColor(skity::ColorSetARGB(255, 40, 40, 255));
    canvas->drawSimpleText2(text, x + w * 0.5f - tw * 0.5f + iw * 0.25f,y + h * 0.7f, paint);


}

void clearScreen(skity::Canvas* canvas)
{
    skity::Paint paint;
    paint.setAntiAlias(true);
    paint.setStyle(skity::Paint::kFill_Style);
    skity::Rect rect;
    rect.setXYWH(0,0,canvas->width(),canvas->height());
    paint.setColor(skity::ColorSetARGB(255, 0, 0, 0));
    canvas->drawRect(rect, paint);
}

void draw_point(skity::Canvas* canvas,int x,int y)
{
    skity::Paint paint;
    paint.setAntiAlias(true);
    paint.setStyle(skity::Paint::kFill_Style);
    skity::Rect rect;
    rect.setXYWH(x-50,y-50,100,100);
    paint.setColor(skity::ColorSetARGB(255, 255, 255, 255));
    canvas->drawRect(rect, paint);
}

void draw_canvas(skity::Canvas* canvas,int mx,int my,int mButton,
                 std::shared_ptr<skity::Typeface> typeface,
                 std::shared_ptr<skity::Typeface> typeface_emoji
)
{
    clearScreen(canvas);
draw_point(canvas,mx,my);
/*
    draw_button(canvas,"\uF15C","button",0,0,500,100,
                skity::ColorSetARGB(255, 55, 255, 55),
                typeface,typeface_emoji
                );*/
}
