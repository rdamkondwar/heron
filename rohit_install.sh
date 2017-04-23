bazel build --config=ubuntu heron/...

bazel build --config=ubuntu scripts/packages:binpkgs
bazel build --config=ubuntu scripts/packages:tarpkgs

./bazel-bin/scripts/packages/heron-client-install.sh --user
./bazel-bin/scripts/packages/heron-tools-install.sh --user
