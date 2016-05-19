# We should get an error with any command line option
./main -v
RETVAL=$?
if [ $RETVAL == 0 ]; then
  exit 1
else
  exit 0
fi
