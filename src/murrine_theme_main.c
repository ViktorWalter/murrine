/* Murrine theme engine
 * Copyright (C) 2006-2007-2008-2009 Andrea Cimitan
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */

#include <gmodule.h>
#include <gtk/gtk.h>

#include "murrine_engine.h"

G_MODULE_EXPORT void
theme_init (GTypeModule *module)
{
//	printf ("Murrine 0.91.x Development Snapshot, Copyright Andrea Cimitan\n"); 
	murrine_engine_register_types (module);
}

G_MODULE_EXPORT void
theme_exit (void)
{
}

G_MODULE_EXPORT GtkThemingEngine *
theme_create_engine (void)
{
	return GTK_THEMING_ENGINE (g_object_new (MURRINE_TYPE_ENGINE,
	                                         "name", "murrine",
	                                         NULL));
}

/* The following function will be called by GTK+ when the module
 * is loaded and checks to see if we are compatible with the
 * version of GTK+ that loads us.
 */
G_MODULE_EXPORT const gchar* g_module_check_init (GModule *module);
const gchar*
g_module_check_init (GModule *module)
{
	return gtk_check_version (GTK_MAJOR_VERSION,
	                          GTK_MINOR_VERSION,
	                          GTK_MICRO_VERSION - GTK_INTERFACE_AGE);
}
