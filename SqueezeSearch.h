/*
    Copyright (C) 2010 Michael Rahr

    This file is part of SqueezeRemote.

    SqueezeRemote is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License.

    SqueezeRemote is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with SqueezeRemote.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef SQUEEZESEARCH_H
#define SQUEEZESEARCH_H

typedef struct{
QString albumId;
QString albumName;
} SqueezeSearchAlbum;

typedef struct{
QString trackId;
QString trackName;
} SqueezeSearchTrack;

typedef struct{
QString ContributorId;
QString ContributorName;
} SqueezeSearchContributor;


#endif // SQUEEZESEARCH_H
