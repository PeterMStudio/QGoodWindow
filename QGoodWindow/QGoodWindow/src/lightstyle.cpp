/*
The MIT License (MIT)

Copyright © 2018, Juergen Skrotzky (https://github.com/Jorgen-VikingGod, JorgenVikingGod@gmail.com)
Copyright © 2018-2024 Antonio Dias (https://github.com/antonypro)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "lightstyle.h"
#include "stylecommon.h"

LightStyle::LightStyle() : WindowStyleBase(styleBase())
{

}

LightStyle::LightStyle(QStyle *style) : WindowStyleBase(style)
{

}

LightStyle::~LightStyle()
{

}

void LightStyle::polish(QPalette &palette)
{
    palette.setColor(QPalette::Window, QColor(240, 240, 240));
    palette.setColor(QPalette::WindowText, QColor(0, 0, 0));
    palette.setColor(QPalette::Disabled, QPalette::WindowText, QColor(120, 120, 120));
    palette.setColor(QPalette::Base, QColor(255, 255, 255));
    palette.setColor(QPalette::AlternateBase, QColor(233, 231, 227));
    palette.setColor(QPalette::ToolTipBase, QColor(255, 255, 220));
    palette.setColor(QPalette::ToolTipText, QColor(0, 0, 0));
    palette.setColor(QPalette::Text, QColor(0, 0, 0));
    palette.setColor(QPalette::Disabled, QPalette::Text, QColor(120, 120, 120));
    palette.setColor(QPalette::Dark, QColor(160, 160, 160));
    palette.setColor(QPalette::Shadow, QColor(105, 105, 105));
    palette.setColor(QPalette::Button, QColor(240, 240, 240));
    palette.setColor(QPalette::ButtonText, QColor(0, 0, 0));
    palette.setColor(QPalette::Disabled, QPalette::ButtonText, QColor(120, 120, 120));
    palette.setColor(QPalette::BrightText, QColor(0, 0, 255));
    palette.setColor(QPalette::Link, QColor(51, 153, 255));
    palette.setColor(QPalette::Highlight, QColor(0, 0, 255));
    palette.setColor(QPalette::Disabled, QPalette::Highlight, QColor(51, 153, 255));
    palette.setColor(QPalette::HighlightedText, QColor(255, 255, 255));
    palette.setColor(QPalette::Disabled, QPalette::HighlightedText, QColor(255, 255, 255));
}

void LightStyle::polish(QApplication *app)
{
    if (!app)
        return;

    QFont defaultFont = app->font();
    defaultFont.setPointSize(defaultFont.pointSize() + 2);
    app->setFont(defaultFont);

    QFile file(QStringLiteral(":/lightstyle.qss"));

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString style_sheet = QString::fromLatin1(file.readAll());
        app->setStyleSheet(style_sheet);
        file.close();
    }
}

void LightStyle::unpolish(QApplication *app)
{
    if (!app)
        return;

    QFont defaultFont = app->font();
    defaultFont.setPointSize(defaultFont.pointSize() - 2);
    app->setFont(defaultFont);
}

QStyle *LightStyle::baseStyle() const
{
    return styleBase();
}
