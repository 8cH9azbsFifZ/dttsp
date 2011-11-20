# Cleanup
rm *.changes *.upload
cd dttsp*;
#make clean
rm debian/debhelper.log

# Get sources
#( ./debian/rules get-orig-source ; mv *gz .. )

# Build package #checksum not updated
debuild || exit
debuild -S || exit 
#dpkg-buildpackage

git commit -a -m "new build"

lintian --pedantic --all *dsc
lintian  *deb

# Upload
#git push
#for f in *changes; do
#dput -l debexpo $f
#done
