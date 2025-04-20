#!/usr/bin/env sh

# Replicate the functionality of running from dev-c++ on normal terminals

if [ "$#" -ne 1 ]; then
  echo "Insert only the path to execute"
  exit 1
fi

# Get script path so it's not hardcoded
SOURCE=${BASH_SOURCE[0]}
while [ -L "$SOURCE" ]; do # resolve $SOURCE until the file is no longer a symlink
  DIR=$( cd -P "$( dirname "$SOURCE" )" >/dev/null 2>&1 && pwd )
  SOURCE=$(readlink "$SOURCE")
  [[ $SOURCE != /* ]] && SOURCE=$DIR/$SOURCE # if $SOURCE was a relative symlink, we need to resolve it relative to the path where the symlink file was located
done
DIR=$( cd -P "$( dirname "$SOURCE" )" >/dev/null 2>&1 && pwd )

# Change to current directory
cd "$DIR"

# Execute script
echo

START=$(date +%s,%N)
"$1"
return_val=$(echo $?)
END=$(date +%s,%N)

# Calculate time spent
_s1=$(echo $START | cut -d',' -f1)   # sec
_s2=$(echo $START | cut -d',' -f2)   # nano sec
_e1=$(echo $END | cut -d',' -f1)
_e2=$(echo $END | cut -d',' -f2)
time_cost=$(printf '%.3f\n' "$(bc <<< "scale=5; $_e1 - $_s1 + ($_e2 - $_s2)/1000000000")")

echo "--------------------------------"
echo "Process exited after $time_cost seconds with return value $return_val"
echo "Press any key to continue . . ."
echo

# vim: sw=2
