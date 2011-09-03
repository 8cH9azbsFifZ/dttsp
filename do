rm *.changes *.upload
cd dttsp*
#make clean
rm debian/debhelper.log

#./debian/rules get-orig-source
#mv sdr*gz ..

#checksum not updated
debuild
#debuild -S
#dpkg-buildpackage

cd ..
cd dttsp*
make clean
rm debian/debhelper.log
cd ..

git commit -a -m "new build"
git push

lintian --pedantic --all *dsc
lintian  *deb

#for f in *changes; do
#dput -l debexpo $f
#done
