#include <jni.h>
#include <skity/skity.hpp>
#include <skity/gpu/gpu_context.hpp>
#include <EGL/egl.h>

//
// Created by caichao on 2023/3/12.
//

//implements in example.cc
void draw_canvas(skity::Canvas* canvas,int mx,int my,int mButton,std::shared_ptr<skity::Typeface> typeface,std::shared_ptr<skity::Typeface> typefface_emoji);
//void render_frame(skity::Canvas* canvas, std::shared_ptr<skity::Typeface> const& typeface);
int mx=0;
int my=0;
int mButton=0;

class GLExample{
public:

    explicit GLExample(int wid, int hei)
    {
        assert(wid > 0 && hei > 0);
        skity::GPUContext ctx{skity::GPUBackendType::kOpenGL,
                              (void*)eglGetProcAddress};
        mCanvas = skity::Canvas::MakeHardwareAccelationCanvas(wid,hei,1, &ctx);
        typeface = skity::Typeface::MakeFromFile("/sdcard/SkityDemo/Roboto Mono Nerd Font Complete.ttf");
        emoji_typeface =  skity::Typeface::MakeFromFile("/sdcard/SkityDemo/entypo.ttf");
        mCanvas->setDefaultTypeface(typeface);
        //mCanvas->setDefaultTypeface(skity::Typeface::MakeFromFile("/sdcard/SkityDemo/Roboto Mono Nerd Font Complete.ttf"));
    }

    void Render(){
        draw_canvas(mCanvas.get(),mx,my,mButton,typeface,emoji_typeface);
        // render_frame(mCanvas.get(), mCanvas->getDefaultTypeface() );
        mCanvas->flush();
    }

protected:
    std::unique_ptr<skity::Canvas> mCanvas;
    std::shared_ptr<skity::Typeface> typeface;
    std::shared_ptr<skity::Typeface> emoji_typeface;
};


extern "C"
JNIEXPORT jlong JNICALL
Java_com_example_skitydemo_MainActivity_CreateGLExample(JNIEnv *env, jobject thiz,jint width,jint height) {
    auto glExample = new GLExample(width,height);
    return (long)(glExample);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_skitydemo_MainActivity_RunGLExample(JNIEnv *env, jobject thiz, jlong instance) {
    GLExample *example = (GLExample*)instance;
    example->Render();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_skitydemo_MainActivity_ReleaseGLExample(JNIEnv *env, jobject thiz,
                                                         jlong instance) {
    GLExample *example = (GLExample*)instance;
    delete example;
}
//-------------------------------
extern "C" JNIEXPORT void JNICALL
Java_com_example_skitydemo_MainActivity_PressHandle(JNIEnv *env, jobject thiz,jint x,jint y)
{
    mx=x;
    my=y;
    mButton=1;
}

//-------------------------------
extern "C" JNIEXPORT void JNICALL
Java_com_example_skitydemo_MainActivity_ReleaseHandle(JNIEnv *env, jobject thiz,jint x,jint y)
{
    mx=x;
    my=y;
    mButton=0;
}
//-------------------------------
extern "C" JNIEXPORT void JNICALL
Java_com_example_skitydemo_MainActivity_MoveHandle(JNIEnv *env, jobject thiz,jint x,jint y)
{
    mx=x;
    my=y;
}