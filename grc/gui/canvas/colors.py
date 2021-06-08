"""
Copyright 2008,2013,2021 Free Software Foundation, Inc.
This file is part of GNU Radio

GNU Radio Companion is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

GNU Radio Companion is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
"""

from __future__ import absolute_import

from gi.repository import Gtk, Gdk, cairo

from .. import Constants


def get_color(color_code):
    color = Gdk.RGBA()
    color.parse(color_code)
    return color.red, color.green, color.blue, color.alpha

#################################################################################
# flowgraph colors
#################################################################################

HIGHLIGHT_COLOR = get_color('#00FFFF')
BORDER_COLOR = get_color('#3AFFE2')
BORDER_COLOR_DISABLED = get_color('#888888')
FONT_COLOR = get_color('#26D8BE')

# Missing blocks stuff
MISSING_BLOCK_BACKGROUND_COLOR = get_color('#000000')
MISSING_BLOCK_BORDER_COLOR = get_color('#48171D')

# Flow graph color constants
FLOWGRAPH_BACKGROUND_COLOR = get_color('#181A1B')
COMMENT_BACKGROUND_COLOR = get_color('#001B33')
FLOWGRAPH_EDGE_COLOR = get_color('#FFFFFF')

# Block color constants
BLOCK_ENABLED_COLOR = get_color('#181A1B')
BLOCK_DISABLED_COLOR = get_color('#181A1B')
BLOCK_BYPASSED_COLOR = get_color('#000000')

# Connection color constants
CONNECTION_ENABLED_COLOR = get_color('#3AFFE2')
CONNECTION_DISABLED_COLOR = get_color('#196056')
CONNECTION_ERROR_COLOR = get_color('#D0021B')

DEFAULT_DOMAIN_COLOR = get_color('#FFFFFF')


#################################################################################
# port colors
#################################################################################

PORT_TYPE_TO_COLOR = {key: get_color(color) for name, key, sizeof, color in Constants.CORE_TYPES}
PORT_TYPE_TO_COLOR.update((key, get_color(color)) for key, (_, color) in Constants.ALIAS_TYPES.items())


#################################################################################
# param box colors
#################################################################################
DARK_THEME_STYLES = b"""
                         #dtype_complex         { background-color: #404552; }
                         #dtype_real            { background-color: #404552; }
                         #dtype_float           { background-color: #404552; }
                         #dtype_int             { background-color: #404552; }

                         #dtype_complex_vector  { background-color: #404552; }
                         #dtype_real_vector     { background-color: #404552; }
                         #dtype_float_vector    { background-color: #404552; }
                         #dtype_int_vector      { background-color: #404552; }

                         #dtype_bool            { background-color: #404552; }
                         #dtype_hex             { background-color: #404552; }
                         #dtype_string          { background-color: #404552; }
                         #dtype_id              { background-color: #404552; }
                         #dtype_stream_id       { background-color: #404552; }
                         #dtype_raw             { background-color: #404552; }

                         #enum_custom           { background-color: #404552; }
                     """
LIGHT_THEME_STYLES = b"""
                         #dtype_complex         { background-color: #404552; }
                         #dtype_real            { background-color: #404552; }
                         #dtype_float           { background-color: #404552; }
                         #dtype_int             { background-color: #404552; }

                         #dtype_complex_vector  { background-color: #404552; }
                         #dtype_real_vector     { background-color: #404552; }
                         #dtype_float_vector    { background-color: #404552; }
                         #dtype_int_vector      { background-color: #404552; }

                         #dtype_bool            { background-color: #404552; }
                         #dtype_hex             { background-color: #404552; }
                         #dtype_string          { background-color: #404552; }
                         #dtype_id              { background-color: #404552; }
                         #dtype_stream_id       { background-color: #404552; }
                         #dtype_raw             { background-color: #404552; }

                         #enum_custom           { background-color: #404552; }
                    """
