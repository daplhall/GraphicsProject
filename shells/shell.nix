# bin/nix/shell.nix
{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    gcc
    clang
    sdl3
    cmake
    stdenv.cc.libc  # Explicitly ensures standard C library headers are present
    clang-tools
  ];
  shellHook = ''
    echo "Welcome to the Nix development environment!"
  '';
}
