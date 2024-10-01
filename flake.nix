{
  description = "C++ development environment with Catch2";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in
      {
        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [
            gcc
            gnumake
            catch2_3
            pkg-config
          ];

          shellHook = ''
            echo "C++ development environment loaded"
            echo "Catch2 version: $(pkg-config --modversion catch2)"
          '';
        };
      });
}
