size = 32x32
actioniconsdir = $(pkgdatadir)/icons/hicolor/$(size)/actions
appiconsdir = $(datadir)/icons/hicolor/$(size)/apps

dist_appicons_DATA = \
	apps/eog.png
dist_actionicons_DATA = \
	actions/eog-plugin.png	  	\
	actions/eog-image-gallery.png  \
	actions/slideshow-play.png

noinst_DATA = \
	actions/eog-image-gallery.svg  \
	actions/eog-plugin.svg  \
	actions/slideshow-play.svg

EXTRA_DIST = $(noinst_DATA)

-include $(top_srcdir)/git.mk
