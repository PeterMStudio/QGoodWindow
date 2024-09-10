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

#ifndef WINDOWSTYLEBASE
#define WINDOWSTYLEBASE

#include <QtCore>
#include <QtGui>
#include <QtWidgets>

//\cond HIDDEN_SYMBOLS
class WindowStyleBase : public QProxyStyle
{
Q_OBJECT
public:
    explicit WindowStyleBase();

    WindowStyleBase(QStyle *style);

    ~WindowStyleBase();

    virtual QStyle *styleBase() const;

    virtual QIcon standardIcon(StandardPixmap standardPixmap, const QStyleOption *option, const QWidget *widget) const override;

    virtual void polish(QPalette &palette) override;

    virtual void polish(QApplication *app) override;

    virtual void unpolish(QApplication *app) override;

private:
    //Functions
    QStyle *baseStyle() const ;

    //Variables
#ifdef Q_OS_WIN
    QHash<StandardPixmap, QPixmap> m_hash_pixmap_cache;
#endif
};
//\endcond

#endif // WINDOWSTYLEBASE
