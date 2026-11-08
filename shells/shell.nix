# bin/nix/shell.nix
{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    sdl3
    cmake
    stdenv.cc.cc
    gdb
  ];
  shellHook = ''
    echo "Welcome to the Nix development environment!"
  '';
}
