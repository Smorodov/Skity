
#include <math.h>

#include <array>
#include <cstdlib>
#ifndef SKITY_ANDROID
#include <skity/codec/codec.hpp>
#endif
#include <glm/glm.hpp>
#include <skity/skity.hpp>
#include <string>

#include "perf.hpp"

void render_frame(skity::Canvas* canvas,
                  std::shared_ptr<skity::Typeface> const& typeface,
                  std::shared_ptr<skity::Typeface> const& emoji, float mx,
                  float my, float width, float height, float t);



void draw_window(skity::Canvas* canvas, const char* title, float x, float y,
                 float w, float h);
void draw_label(skity::Canvas* canvas, const char* text, float x, float y,
                float w, float h);

void draw_edit_box_base(skity::Canvas* canvas, float x, float y, float w,
                        float h);
void draw_edit_box(skity::Canvas* canvas, const char* text, float x, float y,
                   float w, float h);
void draw_edit_box_num(skity::Canvas* canvas, const char* text,
                       const char* units, float x, float y, float w, float h);
void draw_check_box(skity::Canvas* canvas, const char* text, float x, float y,
                    float w, float h);

void draw_button(skity::Canvas* canvas, const char* pre_icon, const char* text,
                 float x, float y, float w, float h, skity::Color col);

void draw_slider(skity::Canvas* canvas, float pos, float x, float y, float w,
                 float h);

void render_frame(skity::Canvas* canvas,
                  std::shared_ptr<skity::Typeface> const& typeface,
                  std::shared_ptr<skity::Typeface> const& emoji, float mx,
                  float my, float width, float height, float t) {
  float x, y, popy;
  
  draw_slider(canvas, 0.5, 5,80, 200, 30);
  /*
  // widgets
  draw_window(canvas, "Widgets 'n Stuff", 50, 50, 300, 400);
  x = 60;
  y = 95;

  // Form
  draw_label(canvas, "Login", x, y, 280, 20);
  y += 25.f;
  draw_edit_box(canvas, "Email", x, y, 280, 28);
  y += 35.f;
  draw_check_box(canvas, "Remember me", x, y, 140, 28);
  draw_button(canvas, "\ufafb", "Sign in", x + 138.f, y, 140, 28,
              skity::ColorSetARGB(255, 0, 96, 128));

  y += 45.f;
  // Slider
  draw_label(canvas, "Diameter", x, y, 280, 20);
  y += 25.f;
  draw_edit_box_num(canvas, "123.00", "px", x + 180, y, 100, 28);
  draw_slider(canvas, 0.4f, x, y, 170, 28);

  y += 55;
  draw_button(canvas, "\uf1f8" , "Delete", x, y, 160, 28,
              skity::ColorSetARGB(255, 128, 16, 8));
  draw_button(canvas, nullptr, "Cancel", x + 170, y, 110, 28,
              skity::Color_TRANSPARENT);
  */
}
void draw_window(skity::Canvas* canvas, const char* title, float x, float y,
                 float w, float h) {
  float corner_radius = 3.f;
  skity::Paint paint;
  paint.setAntiAlias(true);
  paint.setStyle(skity::Paint::kFill_Style);
  skity::RRect rrect;
  // window
  rrect.setRectXY(skity::Rect::MakeXYWH(x - 5, y - 5, w + 10, h + 10),
                  corner_radius, corner_radius);
  paint.setColor(skity::ColorSetARGB(64, 0, 0, 0));
  canvas->drawRRect(rrect, paint);
  paint.setColor(skity::ColorSetARGB(192, 28, 30, 34));
  rrect.setRectXY(skity::Rect::MakeXYWH(x, y, w, h), corner_radius,
                  corner_radius);
  canvas->drawRRect(rrect, paint);
  // header
  std::array<skity::Color4f, 2> colors{};
  colors[0] = skity::Color4fFromColor(skity::ColorSetARGB(8, 255, 255, 255));
  colors[1] = skity::Color4fFromColor(skity::ColorSetARGB(16, 0, 0, 0));
  std::array<skity::Point, 2> pts{skity::Point{x, y, 0, 1},
                                  skity::Point{x, y + 15, 0.f, 1.f}};
  paint.setShader(
      skity::Shader::MakeLinear(pts.data(), colors.data(), nullptr, 2));
  rrect.setRectXY(skity::Rect::MakeXYWH(x + 1, y + 1, w - 2, 30),
                  corner_radius - 1.f, corner_radius - 1.f);
  canvas->drawRRect(rrect, paint);
  paint.setShader(nullptr);
  paint.setStyle(skity::Paint::kStroke_Style);
  paint.setColor(skity::ColorSetARGB(32, 0, 0, 0));
  skity::Path header;
  header.moveTo(x + 0.5f, y + 0.5f + 30.f);
  header.lineTo(x + 0.5f + w - 1.f, y + 0.5f + 30.f);
  canvas->drawPath(header, paint);
  paint.setTextSize(16.f);
  paint.setStyle(skity::Paint::kFill_Style);
  paint.setColor(skity::ColorSetARGB(160, 220, 220, 220));
  canvas->drawSimpleText2(title, x + w / 2.f - 80.f, y + 16 + 2, paint);
}

void draw_label(skity::Canvas* canvas, const char* text, float x, float y,
                float w, float h) {
  skity::Paint paint;
  paint.setAntiAlias(true);
  paint.setStyle(skity::Paint::kFill_Style);
  paint.setColor(skity::ColorSetARGB(128, 255, 255, 255));
  paint.setTextSize(15.f);
  canvas->drawSimpleText2(text, x, y + h * 0.9f, paint);
}

void draw_edit_box_base(skity::Canvas* canvas, float x, float y, float w,
                        float h) {
  skity::Paint paint;
  paint.setAntiAlias(true);
  paint.setStyle(skity::Paint::kFill_Style);
  paint.setColor(skity::ColorSetARGB(32, 255, 255, 255));
  skity::RRect rrect;
  rrect.setRectXY(skity::Rect::MakeXYWH(x + 1.f, y + 1.f, w - 2.f, h - 2.f),
                  3.f, 3.f);
  canvas->drawRRect(rrect, paint);
  paint.setColor(skity::ColorSetARGB(48, 0, 0, 0));
  paint.setStyle(skity::Paint::kStroke_Style);
  rrect.setRectXY(skity::Rect::MakeXYWH(x + 0.5f, y + 0.5f, w - 1.f, h - 1.f),
                  3.5f, 3.5f);
  canvas->drawRRect(rrect, paint);
}

void draw_edit_box(skity::Canvas* canvas, const char* text, float x, float y,
                   float w, float h) {
  draw_edit_box_base(canvas, x, y, w, h);
  skity::Paint paint;
  paint.setAntiAlias(true);
  paint.setTextSize(17.f);
  paint.setStyle(skity::Paint::kFill_Style);
  paint.setColor(skity::ColorSetARGB(64, 255, 255, 255));
  canvas->drawSimpleText2(text, x + h * 0.3f, y + h * 0.7f, paint);
}

void draw_check_box(skity::Canvas* canvas, const char* text, float x, float y,
                    float w, float h) {
  skity::Paint paint;
  paint.setAntiAlias(true);
  paint.setTextSize(15.f);
  paint.setStyle(skity::Paint::kFill_Style);
  paint.setColor(skity::ColorSetARGB(160, 255, 255, 255));
  canvas->drawSimpleText2(text, x + 28.f, y + h * 0.7f, paint);
  skity::RRect rrect;
  rrect.setRectXY(
      skity::Rect::MakeXYWH(x + 1.f, y + h * 0.5f - 9.f + 1.f, 18.f, 18.f), 3.f,
      3.f);
  paint.setColor(skity::ColorSetARGB(128, 0, 0, 0));
  canvas->drawRRect(rrect, paint);
  paint.setTextSize(20.f);
  paint.setColor(skity::ColorSetARGB(128, 255, 255, 255));
  std::string icon_check = "\uf00c";
  canvas->drawSimpleText2(icon_check.c_str(), x + 1.f, y + h * 0.8f, paint);
}

void draw_button(skity::Canvas* canvas, const char* pre_icon, const char* text,
                 float x, float y, float w, float h, skity::Color col) {
  float corner_radius = 4.f;
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
  paint.setColor(skity::ColorSetARGB(48, 0, 0, 0));
  rrect.setRectXY(skity::Rect::MakeXYWH(x + 0.5f, y + 0.5f, w - 1.f, h - 1.f),
                  corner_radius - 0.5f, corner_radius - 0.5f);
  canvas->drawRRect(rrect, paint);
  paint.setStyle(skity::Paint::kFill_Style);
  paint.setTextSize(17.f);
  tw = canvas->simpleTextBounds(text, paint).x;
  if (pre_icon) {
    paint.setTextSize(h * 0.8f);
    iw = canvas->simpleTextBounds(pre_icon, paint).x;
    canvas->drawSimpleText2(pre_icon, x + w * 0.5f - tw * 0.5f - iw,
                            y + h * 0.75f, paint);
  }
  paint.setTextSize(17.f);
  paint.setColor(skity::ColorSetARGB(160, 0, 0, 0));
  canvas->drawSimpleText2(text, x + w * 0.5f - tw * 0.5f + iw * 0.25f,
                          y + h * 0.7f - 1.f, paint);
  paint.setColor(skity::ColorSetARGB(160, 255, 255, 255));
  canvas->drawSimpleText2(text, x + w * 0.5f - tw * 0.5f + iw * 0.25f,
                          y + h * 0.7f, paint);
}

void draw_edit_box_num(skity::Canvas* canvas, const char* text,
                       const char* units, float x, float y, float w, float h) {
  float uw;
  draw_edit_box_base(canvas, x, y, w, h);
  skity::Paint paint;
  paint.setAntiAlias(true);
  paint.setTextSize(15.f);
  paint.setStyle(skity::Paint::kFill_Style);
  uw = canvas->simpleTextBounds(units, paint).x;
  paint.setColor(skity::ColorSetARGB(64, 255, 255, 255));
  canvas->drawSimpleText2(units, x + w - h * 0.3f - uw, y + h * 0.6f, paint);
  paint.setTextSize(17.f);
  paint.setColor(skity::ColorSetARGB(128, 255, 255, 255));
  float tw = canvas->simpleTextBounds(text, paint).x;
  canvas->drawSimpleText2(text, x + w - h * 0.5f - uw - tw, y + h * 0.65f,
                          paint);
}

void draw_slider(skity::Canvas* canvas, float pos, float x, float y, float w,float h) {  
    float cy = y + (int)(h * 0.5f);
  float kr = (int)(h * 0.25f);
  skity::Paint paint;
  paint.setAntiAlias(true);
  paint.setStyle(skity::Paint::kFill_Style);
  // Slot
  skity::RRect rrect;
  rrect.setRectXY(skity::Rect::MakeXYWH(x, cy - 2, w, 4), 2, 2);
  paint.setColor(skity::ColorSetARGB(255, 128, 255, 128));
  canvas->drawRRect(rrect, paint);
  // Knob Shadow
  {
    std::array<skity::Color4f, 2> colors{};
    colors[0] = skity::Color4fFromColor(skity::ColorSetARGB(255, 155, 155, 255));
    colors[1] = skity::Color4fFromColor(skity::ColorSetARGB(0, 0, 0, 0));
    paint.setShader(skity::Shader::MakeRadial(
        {x + pos * w, cy + 1.f, 0.f, 1.f}, kr + 3, colors.data(), nullptr, 2));
  }
  skity::Path path;
  path.addRect(skity::Rect::MakeXYWH(x + pos * w - kr - 5, cy - kr - 5,
                                     kr * 2 + 5 + 5, kr * 2 + 5 + 5 + 3));
  path.addCircle(x + pos * w, cy, kr, skity::Path::Direction::kCCW);
  canvas->drawPath(path, paint);
  skity::Path knob;
  knob.addCircle(x + pos * w, cy, kr - 1);
  paint.setShader(nullptr);
  //paint.setColor(skity::ColorSetARGB(255, 40, 43, 48));
  paint.setColor(skity::ColorSetARGB(255, 255, 255, 255));
  canvas->drawPath(knob, paint);
  {
    std::array<skity::Color4f, 2> colors{};
    std::array<skity::Point, 2> pts{};
    colors[0] = skity::Color4fFromColor(skity::ColorSetARGB(16, 255, 255, 255));
    colors[1] = skity::Color4fFromColor(skity::ColorSetARGB(16, 0, 0, 0));
    pts[0] = {x, cy - kr, 0, 1};
    pts[1] = {x, cy + kr, 0, 1};
    paint.setShader(
        skity::Shader::MakeLinear(pts.data(), colors.data(), nullptr, 2));
  }
  canvas->drawPath(knob, paint);
  skity::Path circle;
  circle.addCircle(x + pos * w, cy, kr - 0.5f);
  paint.setShader(nullptr);
  paint.setColor(skity::ColorSetARGB(92, 0, 0, 0));
  paint.setStyle(skity::Paint::kStroke_Style);
  canvas->drawPath(circle, paint);
}