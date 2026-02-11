//  GenericTemplate.cpp
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


#include "GenericTemplate.hpp"

#include "FrameRect.hpp"

#include <QDebug>


namespace glabels::model
{


        Template GenericTemplate::fullPage( const Paper& paper )
        {
                // TRANSLATORS
                //:   %1 = page size.  (e.g. A4)
                return sheetTemplate( paper, 1, 1, QString( tr( "%1 full-page labels" ) ).arg( paper.name() ) );
        }


        Template GenericTemplate::halfPage1x2( const Paper& paper )
        {
                // TRANSLATORS
                //:   %1 = page size.  (e.g. A4)
                return sheetTemplate( paper, 1, 2, QString( tr( "%1 half-page labels" ) ).arg( paper.name() ) );
        }


        Template GenericTemplate::halfPage2x1( const Paper& paper )
        {
                return sheetTemplate( paper, 2, 1, QString( tr( "%1 half-page labels" ) ).arg( paper.name() ) );
        }


        Template GenericTemplate::quarterPage2x2( const Paper& paper )
        {
                // TRANSLATORS
                //:   %1 = page size.  (e.g. A4)
                return sheetTemplate( paper, 2, 2, QString( tr( "%1 quarter-page labels" ) ).arg( paper.name() ) );
        }


        Template GenericTemplate::envelope( const Paper& paper )
        {
                // TRANSLATORS
                //:   %1 = envelope size.  (e.g. DL)
                QString description = QString( tr( "%1 envelope" ) ).arg( paper.name() );

                Template tmplate( tr("Generic"),
                                  paper.id() + "-ENV",
                                  description,
                                  paper.id(),
                                  paper.width(),
                                  paper.height() );

                FrameRect frame( paper.width(),
                                 paper.height(),
                                 Distance::pt( 0 ),
                                 Distance::pt( 0 ),
                                 Distance::pt( 0 ) );

                Layout layout( 1,
                               1,
                               Distance::pt( 0 ),
                               Distance::pt( 0 ),
                               Distance::pt( 0 ),
                               Distance::pt( 0 ) );

                frame.addLayout( layout );
                tmplate.addFrame( frame );

                tmplate.addCategory( "mail" );

                return tmplate;
        }


        Template GenericTemplate::sheetTemplate( const Paper&   paper,
                                                 int            nx,
                                                 int            ny,
                                                 const QString& description )
        {
                Template tmplate( tr("Generic"),
                                  QString( "%1-%2x%3" ).arg(paper.id()).arg(nx).arg(ny),
                                  description,
                                  paper.id(),
                                  paper.width(),
                                  paper.height() );

                FrameRect frame( paper.width()/nx,
                                 paper.height()/ny,
                                 Distance::pt( 0 ),
                                 Distance::pt( 0 ),
                                 Distance::pt( 0 ) );

                Layout layout( nx,
                               ny,
                               Distance::pt( 0 ),
                               Distance::pt( 0 ),
                               paper.width()/nx,
                               paper.height()/ny );

                frame.addLayout( layout );
                tmplate.addFrame( frame );

                tmplate.addCategory( "label" );
                tmplate.addCategory( "rectangle-label" );
                tmplate.addCategory( "card" );

                return tmplate;
        }


}
