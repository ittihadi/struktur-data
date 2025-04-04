const std = @import("std");

pub fn build(b: *std.Build) void {
    const optimize = b.standardOptimizeOption(.{});
    const target = b.standardTargetOptions(.{});

    const files = .{
        "Array_2D_01_Traversal.c",
        "Array_2D_02_Tambah.c",
        "Array_2D_03_Baca.c",
        "Array_2D_04_Update.c",
        "Array_2D_05_Hapus.c",
        "Array_2D_06_01_Matrix_Addition.c",
        "Array_2D_06_02_Penilaian_Mahasiswa.c",
        "Pointer_01_Introduction.c",
        "Pointer_02_Pointer_and_Arrays.c",
        "Pointer_03_Pointer_and_Strings.c",
        "Pointer_04_Function_Pointers.c",
        "Pointer_05_Struct_Pointers.c",
        "Pointer_06_01_Student_Data_Management_with_Pointers_to_Structs.c",
        "Pointer_06_02_Item_Table_Data_Management_using_Pointers.c",
    };

    const build_all_step = b.step("all", "Builds all files");

    inline for (files) |file| {
        const exe = b.addExecutable(.{
            .name = file[0 .. file.len - 2],
            .target = target,
            .optimize = optimize,
            .link_libc = true,
        });

        exe.addCSourceFile(.{ .file = b.path(file) });
        b.installArtifact(exe);

        build_all_step.dependOn(&exe.step);
    }
}
