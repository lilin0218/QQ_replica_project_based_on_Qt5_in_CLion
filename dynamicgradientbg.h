#ifndef DYNAMICGRADIENTBG_H
#define DYNAMICGRADIENTBG_H

#include <QWidget>
#include <QColor>
#include <QTimer>

class DynamicGradientBG : public QWidget
{
    Q_OBJECT
public:
    explicit DynamicGradientBG(QWidget *parent=nullptr);
    //添加一组色彩渐变（添加多组时会循环播放）
    void addGradientPair(const QColor &start,const QColor &end);
    //开始动画，入参为切换时间ms
    void startAnimation(int interval=1000);
    //将动态渐变色背景安装到目标widget(对外暴露)
    static void installDynamicGradientBG(QWidget *target);
protected:
    void paintEvent(QPaintEvent *event)override;
private:
    QList<QPair<QColor,QColor> > m_gradientPairs;
    int  m_currentIndex;
    float m_progress;
    QTimer m_updateTimer;//刷新计时器
    QTimer m_switchTimer;//控制切换时间
    // 插值函数：根据 t(0~1) 计算 a 和 b 之间的中间色
    QColor interpolate(const QColor &a,const QColor &b,float t);
};

#endif // DYNAMICGRADIENTBG_H
