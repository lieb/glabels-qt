/*  FrameCd.h
 *
 *  Copyright (C) 2013-2016  Jaye Evins <evins@snaught.com>
 *
 *  This file is part of gLabels-qt.
 *
 *  gLabels-qt is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  gLabels-qt is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with gLabels-qt.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef model_FrameCd_h
#define model_FrameCd_h


#include "Frame.h"


namespace glabels
{
	namespace model
	{

		class FrameCd : public Frame
		{
			Q_DECLARE_TR_FUNCTIONS(FrameCd)

		public:
			FrameCd( const Distance& r1,
			         const Distance& r2,
			         const Distance& w,
			         const Distance& h,
			         const Distance& waste,
			         const QString&  id = "0" );

			FrameCd( const FrameCd &other ) = default;

			Frame *dup() const override;

			Distance r1() const;
			Distance r2() const;
			Distance waste() const;

			Distance w() const override;
			Distance h() const override;

			QString sizeDescription( const Units& units ) const override;
			bool isSimilarTo( Frame* other ) const override;

			const QPainterPath& path() const override;
			const QPainterPath& clipPath() const override;
			QPainterPath marginPath( const Distance& xSize,
			                         const Distance& ySize ) const override;


		private:
			Distance mR1;
			Distance mR2;
			Distance mW;
			Distance mH;
			Distance mWaste;

			QPainterPath mPath;
			QPainterPath mClipPath;

		};

	}
}


// Debugging support
QDebug operator<<( QDebug dbg, const glabels::model::FrameCd& frame );


#endif // model_FrameCd_h
