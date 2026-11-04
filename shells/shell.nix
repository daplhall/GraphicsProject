# bin/nix/shell.nix
{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = [
    pkgs.gcc
    pkgs.clang
    pkgs.sdl3
    pkgs.cmake
  ];

  shellHook = ''
    echo "Welcome to the Nix development environment!"
  '';
}
