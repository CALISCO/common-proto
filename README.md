# common-proto
shared protobuf definitions and compiled code

# Repository Structure
Protocol files should be in their own directories, like `telemetry/`.

Generated protocol files are committed to the repository, in `generated/`. This is so this repository can be submoduled and used without all users needing to recompile proto files (and needing to set up the entire toolchain).

A `build/` directory is produced during the build, for built files that are not the final output, like the nanopb internals. These are not committed.

# Building

## Toolchain setup
1.  Install [`protoc`](https://developers.google.com/protocol-buffers/), the protobuf compiler.
    - On Windows: [download the latest release here](https://github.com/google/protobuf/releases), extract the binary somewhere, and add it to your system PATH.
    - On Debian-based systems, this is available as a package:

      ```
      scons apt-get install protobuf-compiler
      ```

1.  Install the Python protobuf package. This is needed for the [nanopb](https://github.com/nanopb/nanopb) compiler.
    - On Windows, install it through pip:

      ```
      pip2 install protobuf
      ```

    - On Debian-based systems, this is available as a package:

      ```
      sudo apt-get install python-protobuf
      ```

1.  Install [SCons](http://scons.org/), the build system.
     - On Debian-based systems, this is available as a package:

       ```
       sudo apt-get install scons
       ```

     - On Windows, [download and run this installer](http://scons.org/pages/download.html). You will need to install [Python 2.7, 32-bit](https://www.python.org/downloads/) if you do not have it already (as of SCons 2.5.0, there is no Python3 support yet and the installer will not detect 64-bit Python versions).
      - Make sure to add SCons to your system PATH. By default, SCons will be installed in the `Scripts` folder under your Python directory.

## IDE setup
_This section is optional, for people who want to work with an IDE._

1.  [Download Eclipse](https://www.eclipse.org/downloads/). Eclipse IDE for C/C++ developers is a good option.
1.  Install some Eclipse plugins:
    - (menu) > Help > Install New Software..., then enter the update site URL in the "Work with..." field.
    - If some components cannot be installed, you may need to update your version of Eclipse.
    - Install [SConsolidator](http://www.sconsolidator.com/) (update site: <http://www.sconsolidator.com/update>), which allows some integration of SCons scripts.
    - Install [protobuf-dt](https://github.com/google/protobuf-dt) (update site: <http://google.github.io/protobuf-dt/updates/latest/>), a plugin for editing proto files.
