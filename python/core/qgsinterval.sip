/************************************************************************
 * This file has been generated automatically from                      *
 *                                                                      *
 * src/core/qgsinterval.h                                               *
 *                                                                      *
 * Do not edit manually ! Edit header and run scripts/sipify.pl again   *
 ************************************************************************/







class QgsInterval
{
%Docstring
 A representation of the interval between two datetime values.
.. versionadded:: 2.16
%End

%TypeHeaderCode
#include "qgsinterval.h"
%End
  public:

    static const int YEARS;
%Docstring
Seconds per year (average)
%End
    static const int MONTHS;
%Docstring
Seconds per month, based on 30 day month
%End
    static const int WEEKS;
%Docstring
Seconds per week
%End
    static const int DAY;
%Docstring
Seconds per day
%End
    static const int HOUR;
%Docstring
Seconds per hour
%End
    static const int MINUTE;
%Docstring
Seconds per minute
%End

    QgsInterval();
%Docstring
 Default constructor for QgsInterval. Creates an invalid interval.
%End

    QgsInterval( double seconds );
%Docstring
 Constructor for QgsInterval.
 \param seconds duration of interval in seconds
%End

    double years() const;
%Docstring
 Returns the interval duration in years (based on an average year length)
.. seealso:: setYears()
 :rtype: float
%End

    void setYears( double years );
%Docstring
 Sets the interval duration in years.
 \param years duration in years (based on average year length)
.. seealso:: years()
%End

    double months() const;
%Docstring
 Returns the interval duration in months (based on a 30 day month).
.. seealso:: setMonths()
 :rtype: float
%End

    void setMonths( double months );
%Docstring
 Sets the interval duration in months.
 \param months duration in months (based on a 30 day month)
.. seealso:: months()
%End

    double weeks() const;
%Docstring
 Returns the interval duration in weeks.
.. seealso:: setWeeks()
 :rtype: float
%End

    void setWeeks( double weeks );
%Docstring
 Sets the interval duration in weeks.
 \param weeks duration in weeks
.. seealso:: weeks()
%End

    double days() const;
%Docstring
 Returns the interval duration in days.
.. seealso:: setDays()
 :rtype: float
%End

    void setDays( double days );
%Docstring
 Sets the interval duration in days.
 \param days duration in days
.. seealso:: days()
%End

    double hours() const;
%Docstring
 Returns the interval duration in hours.
.. seealso:: setHours()
 :rtype: float
%End

    void setHours( double hours );
%Docstring
 Sets the interval duration in hours.
 \param hours duration in hours
.. seealso:: hours()
%End

    double minutes() const;
%Docstring
 Returns the interval duration in minutes.
.. seealso:: setMinutes()
 :rtype: float
%End

    void setMinutes( double minutes );
%Docstring
 Sets the interval duration in minutes.
 \param minutes duration in minutes
.. seealso:: minutes()
%End

    double seconds() const;
%Docstring
 Returns the interval duration in seconds.
.. seealso:: setSeconds()
 :rtype: float
%End

    void setSeconds( double seconds );
%Docstring
 Sets the interval duration in seconds.
 \param seconds duration in seconds
.. seealso:: seconds()
%End

    bool isValid() const;
%Docstring
 Returns true if the interval is valid.
.. seealso:: setValid()
 :rtype: bool
%End

    void setValid( bool valid );
%Docstring
 Sets whether the interval is valid.
 \param valid set to true to set the interval as valid.
.. seealso:: isValid()
%End

    bool operator==( QgsInterval other ) const;
%Docstring
 :rtype: bool
%End

    static QgsInterval fromString( const QString &string );
%Docstring
 Converts a string to an interval
 \param string string to parse
 :return: interval, or invalid interval if string could not be parsed
 :rtype: QgsInterval
%End

    operator QVariant() const;
%Docstring
Allows direct construction of QVariants from intervals.
%End

};



/************************************************************************
 * This file has been generated automatically from                      *
 *                                                                      *
 * src/core/qgsinterval.h                                               *
 *                                                                      *
 * Do not edit manually ! Edit header and run scripts/sipify.pl again   *
 ************************************************************************/
