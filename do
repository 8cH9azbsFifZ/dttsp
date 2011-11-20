rm *.changes *.upload
cd dttsp*
#make clean
rm debian/debhelper.log

# Get sources
[ -e ../*gz ] || ( ./debian/rules get-orig-source ; mv *gz .. )

# Build package #checksum not updated
debuild 
debuild -S
#dpkg-buildpackage

# Remove logfiles
cd ..
cd dttsp*
rm debian/debhelper.log
cd ..

git commit -a -m "new build"

lintian --pedantic --all *dsc
lintian  *deb

# Upload
#git push
#for f in *changes; do
#dput -l debexpo $f
#done
