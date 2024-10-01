{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = [ pkgs.catch2_3 pkgs.pkg-config ];
}
