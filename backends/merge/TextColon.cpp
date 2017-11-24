/*  Merge/TextColon.cpp
 *
 *  Copyright (C) 2016  Jim Evins <evins@snaught.com>
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

#include "TextColon.h"


namespace glabels::merge
{

	static const QString ID = "Text/Colon";


	///
	/// Constructor
	///
	TextColon::TextColon() : Text(':',false)
	{
		mId = ID;
	}


	///
	/// Constructor
	///
	TextColon::TextColon( const TextColon* merge ) : Text( merge )
	{
	}


	///
	/// Destructor
	///
	TextColon::~TextColon()
	{
	}


	///
	/// Clone
	///
	TextColon* TextColon::clone() const
	{
		return new TextColon( this );
	}


	///
	/// Get ID
	///
	QString TextColon::id()
	{
		return ID;
	}


	///
	/// Create
	///
	Merge* TextColon::create()
	{
		return new TextColon();
	}

} // namespace glabels::merge