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


#include <QString>
#include <QPainter>
#include <QPair>
#include "jkqtplotter/graphs/jkqtpgeobase.h"
#include "jkqtplotter/jkqtpgraphsbasestylingmixins.h"
#include "jkqtplotter/jkqtptools.h"
#include "jkqtplotter/jkqtplotter_imexport.h"
#include "jkqtmathtext/jkqtmathtext.h"

#ifndef jkqtpgeoannotations_H_INCLUDED
#define jkqtpgeoannotations_H_INCLUDED




/*! \brief This virtual JKQTPGraph descendent may be used to display a single symbol (marker).
    \ingroup jkqtplotter_geoplots

    \see \ref JKQTPlotterGeometricGraphs

 */
class JKQTPLOTTER_LIB_EXPORT JKQTPGeoSymbol: public JKQTPPlotObject, public JKQTPGraphSymbolStyleMixin {
        Q_OBJECT
    public:
        /*! \brief class contructor

            \param parent parent plotter widget
            \param x x-coordinate of symbol center
            \param y y-coordinate of symbol center
            \param symbol symbol type
            \param symbolSize size of the symbol in pt
            \param color color of drawing
            \param fillColor fill color of the symbol (if filled)
         */
        JKQTPGeoSymbol(JKQTBasePlotter* parent, double x, double y, JKQTPGraphSymbols symbol=JKQTPCross, double symbolSize=10, QColor color=QColor("black"), QColor fillColor=QColor("grey"));
        /*! \brief class contructor

            \param parent parent plotter widget
            \param x x-coordinate of symbol center
            \param y y-coordinate of symbol center
            \param symbol symbol type
            \param symbolSize size of the symbol in pt
            \param color color of drawing
            \param fillColor fill color of the symbol (if filled)
         */
        JKQTPGeoSymbol(JKQTPlotter* parent, double x, double y, JKQTPGraphSymbols symbol=JKQTPCross, double symbolSize=10, QColor color=QColor("black"), QColor fillColor=QColor("grey"));

        /*! set the symbol color and symbol fill color */
        virtual void setColor(QColor c);

        /*! \copydoc x */ 
        void setX(double __value);
        /*! \copydoc x */ 
        double getX() const;
        /*! \copydoc y */ 
        void setY(double __value);
        /*! \copydoc y */ 
        double getY() const;

        /** \copydoc JKQTPGraph::getXMinMax()        */
        virtual bool getXMinMax(double& minx, double& maxx, double& smallestGreaterZero) override;
        /** \copydoc JKQTPGraph::getYMinMax()        */
        virtual bool getYMinMax(double& miny, double& maxy, double& smallestGreaterZero) override;

        /** \brief plots the graph to the plotter object specified as parent */
        virtual void draw(JKQTPEnhancedPainter& painter) override;

        /** \brief plots a key marker inside the specified rectangle \a rect */
        virtual void drawKeyMarker(JKQTPEnhancedPainter& painter, QRectF& rect) override;
        /** \brief returns the color to be used for the key label */
        virtual QColor getKeyLabelColor() const override;

    protected:
        /** \brief x-position (in plot coordinates) of the symbol (symbol center) */
        double x;
        /** \brief y-position (in plot coordinates) of the symbol (symbol center) */
        double y;

};


/*! \brief This JKQTPPlotObject is used to display text. It uses the JKQTMathText
           class in order to display LaTeX formulas.
    \ingroup jkqtplotter_geoplots

    \see \ref JKQTPlotterGeometricGraphs
 */
class JKQTPLOTTER_LIB_EXPORT JKQTPGeoText: public JKQTPPlotObject, public JKQTPGraphTextStyleMixin {
        Q_OBJECT
    public:
        /*! \brief class contructor

            \param parent parent plotter widget
            \param x x-coordinate of text
            \param y y-coordinate of text
            \param text the text to display
            \param color color of drawing
            \param fontSize base font size of text
         */
        JKQTPGeoText(JKQTBasePlotter* parent, double x, double y, const QString& text, double fontSize, QColor color);
        /*! \brief class contructor

            \param parent parent plotter widget
            \param x x-coordinate of text
            \param y y-coordinate of text
            \param text the text to display
            \param color color of drawing
            \param fontSize base font size of text
         */
        JKQTPGeoText(JKQTPlotter* parent, double x, double y, const QString& text, double fontSize, QColor color);
        /*! \brief class contructor

            \param parent parent plotter widget
            \param x x-coordinate of text
            \param y y-coordinate of text
            \param text the text to display
         */
        JKQTPGeoText(JKQTBasePlotter* parent, double x, double y, const QString& text);
        /*! \brief class contructor

            \param parent parent plotter widget
            \param x x-coordinate of text
            \param y y-coordinate of text
            \param text the text to display
         */
        JKQTPGeoText(JKQTPlotter* parent, double x, double y, const QString& text);

        /*! \copydoc text */ 
        void setText(const QString & __value);
        /*! \copydoc text */ 
        QString getText() const;
        /*! \copydoc x */ 
        void setX(double __value);
        /*! \copydoc x */ 
        double getX() const;
        /*! \copydoc y */ 
        void setY(double __value);
        /*! \copydoc y */ 
        double getY() const;

        /** \brief set line and fill color */
        virtual void setColor(QColor c) ;

        /** \copydoc JKQTPPlotObject::getXMinMax()        */
        virtual bool getXMinMax(double& minx, double& maxx, double& smallestGreaterZero) override;
        /** \copydoc JKQTPPlotObject::getYMinMax()        */
        virtual bool getYMinMax(double& miny, double& maxy, double& smallestGreaterZero) override;

        /** \brief plots the graph to the plotter object specified as parent */
        virtual void draw(JKQTPEnhancedPainter& painter) override;

        /** \brief plots a key marker inside the specified rectangle \a rect */
        virtual void drawKeyMarker(JKQTPEnhancedPainter& painter, QRectF& rect) override;
        /** \brief returns the color to be used for the key label */
        virtual QColor getKeyLabelColor() const override;

    protected:
        /** \brief x-position (in plot coordinates) of the text (left/baseline) */
        double x;
        /** \brief y-position (in plot coordinates) of the text (left/baseline) */
        double y;

        /** \brief the text to display */
        QString text;
        /** \brief return a pen, that may be used for drawing */
        QPen getPen(JKQTPEnhancedPainter& painter);
};



#endif // jkqtpgeoannotations_H_INCLUDED
