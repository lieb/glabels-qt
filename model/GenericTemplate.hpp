//  GenericTemplate.hpp
//
//  Copyright (C) 2026  Jaye Evins <evins@snaught.com>
//
//  This file is part of gLabels-qt.
//
//  gLabels-qt is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  gLabels-qt is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with gLabels-qt.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef model_GenericTemplate_hpp
#define model_GenericTemplate_hpp


#include "Template.hpp"
#include "Paper.hpp"

#include <QCoreApplication>


namespace glabels::model
{

        class GenericTemplate
        {
                Q_DECLARE_TR_FUNCTIONS(GenericTemplate)

        public:
                GenericTemplate() = delete;

                static Template fullPage( const Paper& paper );
                static Template halfPage1x2( const Paper& paper );
                static Template halfPage2x1( const Paper& paper );
                static Template quarterPage2x2( const Paper& paper );

                static Template envelope( const Paper& paper );


        private:
                static Template sheetTemplate( const Paper&   paper,
                                               int            nx,
                                               int            ny,
                                               const QString& description );
        };

}


#endif // model_GenericTemplate_hpp
