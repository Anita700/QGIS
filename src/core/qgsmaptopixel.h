/***************************************************************************
                          qgsmaptopixel.h  -  description
                             -------------------
    begin                : Sat Jun 22 2002
    copyright            : (C) 2002 by Gary E.Sherman
    email                : sherman at mrcc.com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#ifndef QGSMAPTOPIXEL
#define QGSMAPTOPIXEL

#include "qgis_core.h"
#include "qgis_sip.h"
#include <QTransform>
#include <vector>
#include "qgsunittypes.h"
#include <cassert>

class QgsPoint;
class QPoint;

/** \ingroup core
  * Perform transforms between map coordinates and device coordinates.
  *
  * This class can convert device coordinates to map coordinates and vice versa.
  */
class CORE_EXPORT QgsMapToPixel
{
  public:

    /**
     * Constructor
     * \param mapUnitsPerPixel Map units per pixel
     * \param centerX X coordinate of map center, in geographical units
     * \param centerY Y coordinate of map center, in geographical units
     * \param widthPixels Output width, in pixels
     * \param heightPixels Output height, in pixels
     * \param rotation clockwise rotation in degrees
     * \since QGIS 2.8
     */
    QgsMapToPixel( double mapUnitsPerPixel, double centerX, double centerY, int widthPixels, int heightPixels, double rotation );

    /**
     * Constructor
     * \param mapUnitsPerPixel Map units per pixel
     */
    QgsMapToPixel( double mapUnitsPerPixel );

    /** Returns a new QgsMapToPixel created using a specified scale and distance unit.
     * \param scale map scale
     * \param dpi screen DPI
     * \param mapUnits map units
     * \returns matching QgsMapToPixel
     * \since QGIS 3.0
     */
    static QgsMapToPixel fromScale( double scale, QgsUnitTypes::DistanceUnit mapUnits, double dpi = 96 );

    /**
     * Constructor
     *
     * Use setParameters to fill
     */
    QgsMapToPixel();

    /**
     * Transform the point from map (world) coordinates to device coordinates
     * \param p Point to transform
     * \returns QgsPoint in device coordinates
     */
    QgsPoint transform( const QgsPoint &p ) const;

    void transform( QgsPoint *p ) const;

    /**
     * Transform the point specified by x,y from map (world)
     * coordinates to device coordinates
     * \param x x cordinate o point to transform
     * \param y y coordinate of point to transform
     * \returns QgsPoint in device coordinates
     */
    QgsPoint transform( qreal x, qreal y ) const;

    /**
     * Transform device coordinates to map coordinates. Modifies the
     * given coordinates in place. Intended as a fast way to do the
     * transform.
     */
    void transformInPlace( double &x, double &y ) const;

    //! \note not available in Python bindings
    void transformInPlace( float &x, float &y ) const SIP_SKIP;

    /**
     * Transform device coordinates to map coordinates. Modifies the
     * given coordinates in place. Intended as a fast way to do the
     * transform.
     * \note not available in Python bindings
     */
    template <class T> SIP_SKIP
    void transformInPlace( QVector<T> &x, QVector<T> &y ) const
    {
      assert( x.size() == y.size() );
      for ( int i = 0; i < x.size(); ++i )
        transformInPlace( x[i], y[i] );
    }

    QgsPoint toMapCoordinates( int x, int y ) const;

    //! Transform device coordinates to map (world) coordinates
    QgsPoint toMapCoordinatesF( double x, double y ) const;

    /**
     * Transform device coordinates to map (world) coordinates
     * \param p Point to be converted to map cooordinates
     * \returns QgsPoint in map coorndiates
     */
    QgsPoint toMapCoordinates( QPoint p ) const;

    QgsPoint toMapPoint( double x, double y ) const;

    /**
     * Set map units per pixel
     * \param mapUnitsPerPixel Map units per pixel
     */
    void setMapUnitsPerPixel( double mapUnitsPerPixel );

    //! Return current map units per pixel
    double mapUnitsPerPixel() const;

    /**
     * Return current map width in pixels
     * The information is only known if setRotation was used
     * \since QGIS 2.8
     */
    int mapWidth() const;

    /**
     * Return current map height in pixels
     * \since QGIS 2.8
     */
    int mapHeight() const;

    /**
     * Set map rotation in degrees (clockwise)
     * \param degrees clockwise rotation in degrees
     * \param cx X ordinate of map center in geographical units
     * \param cy Y ordinate of map center in geographical units
     * \since QGIS 2.8
     */
    void setMapRotation( double degrees, double cx, double cy );

    /**
     * Return current map rotation in degrees
     * \since QGIS 2.8
     */
    double mapRotation() const;

    /**
     * Set parameters for use in transforming coordinates
     * \param mapUnitsPerPixel Map units per pixel
     * \param centerX X coordinate of map center, in geographical units
     * \param centerY Y coordinate of map center, in geographical units
     * \param widthPixels Output width, in pixels
     * \param heightPixels Output height, in pixels
     * \param rotation clockwise rotation in degrees
     * \since QGIS 2.8
     */
    void setParameters( double mapUnitsPerPixel, double centerX, double centerY, int widthPixels, int heightPixels, double rotation );

    //! String representation of the parameters used in the transform
    QString showParameters() const;

    QTransform transform() const;

    /** Returns the center x-coordinate for the transform.
     * \see yCenter()
     * \since QGIS 3.0
     */
    double xCenter() const { return mXCenter; }

    /** Returns the center y-coordinate for the transform.
     * \see xCenter()
     * \since QGIS 3.0
     */
    double yCenter() const { return mYCenter; }

  private:
    double mMapUnitsPerPixel;
    int mWidth;
    int mHeight;
    double mRotation;
    double mXCenter;
    double mYCenter;
    double xMin;
    double yMin;
    QTransform mMatrix;

    bool updateMatrix();
};


#endif // QGSMAPTOPIXEL
