echo "======= Building interfaces ======="

SOURCE_PATH=$(cd "$(dirname "${BASH_SOURCE[0]}")" &> /dev/null && pwd)
pushd $SOURCE_PATH/build/
make all
make clean-objs
popd