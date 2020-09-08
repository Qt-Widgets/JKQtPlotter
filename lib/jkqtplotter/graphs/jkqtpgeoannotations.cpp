/*
    Copyright (c) 2008-2020 Jan W. Krieger (<jan@jkrieger.de>)

    

    This software is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License (LGPL) as published by
    the Free Software Foundation, either version 2.1 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License (LGPL) for more details.

    You should have received a copy of the GNU Lesser General Public License (LGPL)
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/



#include "jkqtplotter/graphs/jkqtpgeoannotations.h"
#include "jkqtplotter/jkqtpbaseplotter.h"
#include "jkqtplotter/jkqtplotter.h"
#include <stdlib.h>
#include <QDebug>
#include <QApplication>
#define SmallestGreaterZeroCompare_xvsgz() if ((xvsgz>10.0*DBL_MIN)&&((smallestGreaterZero<10.0*DBL_MIN) || (xvsgz<smallestGreaterZero))) smallestGreaterZero=xvsgz;




JKQTPGeoText::JKQTPGeoText(JKQTBasePlotter* parent, double x_, double y_, const QString& text_, double fontSize, QColor color):
    JKQTPGeoText(parent, x_, y_, text_)
{
    setTextFontSize(fontSize);
    setTextColor(color);
}

JKQTPGeoText::JKQTPGeoText(JKQTPlotter* parent, double x, double y, const QString& text, double fontSize, QColor color):
    JKQTPGeoText(parent->getPlotter(),x,y,text,fontSize,color)
{
}

JKQTPGeoText::JKQTPGeoText(JKQTBasePlotter *parent, double x_, double y_, const QString& text_):
    JKQTPPlotObject(DrawAsGraphicElement, parent), JKQTPGraphTextStyleMixin(parent), x(x_),y(y_),text(text_)
{

}

JKQTPGeoText::JKQTPGeoText(JKQTPlotter *parent, double x, double y, const QString &text):
    JKQTPGeoText(parent->getPlotter(),x,y,text)
{
}

void JKQTPGeoText::setText(const QString &__value)
{
    this->text = __value;
}

QString JKQTPGeoText::getText() const
{
    return this->text;
}

void JKQTPGeoText::setX(double __value)
{
    this->x = __value;
}

double JKQTPGeoText::getX() const
{
    return this->x;
}

void JKQTPGeoText::setY(double __value)
{
    this->y = __value;
}

double JKQTPGeoText::getY() const
{
    return this->y;
}

void JKQTPGeoText::setColor(QColor c)
{
    setTextColor(c);
}

bool JKQTPGeoText::getXMinMax(double& minx, double& maxx, double& smallestGreaterZero) {
    minx=maxx=x;
    smallestGreaterZero=0;
    if (x>10.0*DBL_MIN) smallestGreaterZero=x;
    return true;
}

bool JKQTPGeoText::getYMinMax(double& miny, double& maxy, double& smallestGreaterZero) {
    miny=maxy=y;
    smallestGreaterZero=0;
    if (y>10.0*DBL_MIN) smallestGreaterZero=y;
    return true;
}

void JKQTPGeoText::draw(JKQTPEnhancedPainter& painter) {
    clearHitTestData();
    painter.save(); auto __finalpaint=JKQTPFinally([&painter]() {painter.restore();});
    parent->getMathText()->setFontRomanOrSpecial(getTextFontName());
    parent->getMathText()->setFontSize(getTextFontSize()*parent->getFontSizeMultiplier());
    parent->getMathText()->setFontColor(getTextColor());
    parent->getMathText()->parse(text);
    parent->getMathText()->draw(painter, transformX(x), transformY(y));

}

void JKQTPGeoText::drawKeyMarker(JKQTPEnhancedPainter& painter, QRectF& rect) {
    painter.save(); auto __finalpaint=JKQTPFinally([&painter]() {painter.restore();});
    painter.setPen(QPen(getTextColor()));
    double y=rect.top()+rect.height()/2.0;
    if (rect.width()>0) painter.drawLine(QLineF(rect.left(), y, rect.right(), y));

}

QColor JKQTPGeoText::getKeyLabelColor() const {
    return getTextColor();
}






JKQTPGeoSymbol::JKQTPGeoSymbol(JKQTBasePlotter *parent, double x, double y, JKQTPGraphSymbols symbol, double symbolSize, QColor color, QColor fillColor):
    JKQTPPlotObject(DrawAsGraphicElement, parent)
{
    this->x=x;
    this->y=y;
    setSymbolType(symbol);
    setSymbolSize(symbolSize);
    setSymbolColor(color);
    setSymbolFillColor(fillColor);
    setSymbolLineWidth(1);
}

JKQTPGeoSymbol::JKQTPGeoSymbol(JKQTPlotter *parent, double x, double y, JKQTPGraphSymbols symbol, double symbolSize, QColor color, QColor fillColor):
    JKQTPGeoSymbol(parent->getPlotter(), x, y, symbol, symbolSize, color, fillColor)
{

}

void JKQTPGeoSymbol::setColor(QColor c)
{
    setSymbolColor(c);
    setSymbolFillColor(JKQTPGetDerivedColor(parent->getCurrentPlotterStyle().graphFillColorDerivationMode, c));
}

void JKQTPGeoSymbol::setX(double __value)
{
    this->x = __value;
}

double JKQTPGeoSymbol::getX() const
{
    return this->x;
}

void JKQTPGeoSymbol::setY(double __value)
{
    this->y = __value;
}

double JKQTPGeoSymbol::getY() const
{
    return this->y;
}

bool JKQTPGeoSymbol::getXMinMax(double &minx, double &maxx, double &smallestGreaterZero)
{
    minx=x;
    maxx=x;
    double xvsgz;
    xvsgz=minx; SmallestGreaterZeroCompare_xvsgz();
    xvsgz=maxx; SmallestGreaterZeroCompare_xvsgz();
    return true;
}

bool JKQTPGeoSymbol::getYMinMax(double &miny, double &maxy, double &smallestGreaterZero)
{
    miny=y;
    maxy=y;
    double xvsgz;
    xvsgz=miny; SmallestGreaterZeroCompare_xvsgz();
    xvsgz=maxy; SmallestGreaterZeroCompare_xvsgz();
    return true;
}

void JKQTPGeoSymbol::draw(JKQTPEnhancedPainter &painter)
{
    clearHitTestData();
    painter.save(); auto __finalpaint=JKQTPFinally([&painter]() {painter.restore();});
    plotStyledSymbol(parent, painter, transformX(x), transformY(y));
    addHitTestData(x,y);
}

void JKQTPGeoSymbol::drawKeyMarker(JKQTPEnhancedPainter &painter, QRectF &rect)
{
    const double minSize=qMin(rect.width(), rect.height());
    double symbolSize=parent->pt2px(painter, this->getSymbolSize());
    if (symbolSize>minSize*0.9) symbolSize=minSize*0.9;
    double symbolWidth=parent->pt2px(painter, this->getSymbolLineWidth()*parent->getLineWidthMultiplier());
    if (symbolWidth>0.3*symbolSize) symbolWidth=0.3*symbolSize;

    painter.save(); auto __finalpaint=JKQTPFinally([&painter]() {painter.restore();});
    JKQTPPlotSymbol(painter, rect.left()+rect.width()/2.0, rect.top()+rect.height()/2.0, getSymbolType(), symbolSize, symbolWidth, getSymbolColor(), getSymbolFillColor());

}

QColor JKQTPGeoSymbol::getKeyLabelColor() const
{
    return getSymbolColor();
}
