/* Eye Of Gnome - Image Private Data 
 *
 * Copyright (C) 2007 The Free Software Foundation
 *
 * Author: Lucas Rocha <lucasr@gnome.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef __EOG_IMAGE_PRIVATE_H__
#define __EOG_IMAGE_PRIVATE_H__

#include "eog-image.h"

G_BEGIN_DECLS

struct _EogImagePrivate {
	GnomeVFSURI      *uri;

	EogImageStatus    status;

	GdkPixbuf        *image;
	GdkPixbuf        *thumbnail;
	
	gint              width;
	gint              height;

	GnomeVFSFileSize  bytes;
	gchar            *file_type;

	/* Holds EXIF raw data */
	guchar           *exif_chunk; 
	guint             exif_chunk_len;

	/* Holds IPTC raw data */
	guchar           *iptc_chunk; 
	guint             iptc_chunk_len;

#ifdef HAVE_EXIF
	gboolean          autorotate;
	gint              orientation;
	ExifData         *exif;
#endif

#ifdef HAVE_LCMS
	cmsHPROFILE       profile;
#endif

	gboolean          modified;

	gchar            *caption;

	gchar            *collate_key;

	GMutex           *status_mutex;

	gboolean          cancel_loading;

	GSList           *undo_stack;

	EogTransform     *trans;

	guint             data_ref_count;
};

G_END_DECLS

#endif /* __EOG_IMAGE_PRIVATE_H__ */