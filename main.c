#include <stdio.h>

int main() {
    int tuoi_benh_nhan[4];
    int co_bao_hiem[4];
    int phi_kham[4];
    int tong_doanh_thu = 0;
    int so_ca_uu_tien = 0;

    printf('=== PHONG KHAM DA KHOA MEDCARE CLINIC ===\n');
    printf('Nhap du lieu dang ky cho 4 benh nhan trong ca sang:\n');

    for (int i = 0; i < 4; i++) {
        printf('\n--- Nhap thong tin Benh nhan thu %d ---\n', i + 1);
        printf('Nhap tuoi: ');
        scanf('%d', &tuoi_benh_nhan[i]);
        printf('Nhap trang thai BHYT (1: Co, 0: Khong): ');
        scanf('%d', &co_bao_hiem[i]);

        // Xu ly loi 1: Do tuoi dị biet (Out-of-range Age)
        if (tuoi_benh_nhan[i] <= 0 || tuoi_benh_nhan[i] > 120) {
            phi_kham[i] = 0;
            continue;
        }

        // Xu ly loi 2: Trạng thái BHYT sai quy chuẩn
        if (co_bao_hiem[i] != 0 && co_bao_hiem[i] != 1) {
            co_bao_hiem[i] = 0; // Tu dong dua ve mac dinh Khong co BHYT
        }

        // Chinh sách thu phí
        if (co_bao_hiem[i] == 1) {
            phi_kham[i] = 40000; // Giam 80%, chi tra 20% cua 200000
        } else {
            phi_kham[i] = 200000; // Gicu nguyen gia chuan
        }

        // Tích lũy doanh thu
        tong_doanh_thu += phi_kham[i];

        // Phân luồng ưu tiên
        if (tuoi_benh_nhan[i] > 70) {
            so_ca_uu_tien++;
        }
    }

    printf('\n==============================================\n');
    printf('      BANG TONG HOP KET QUA KHI KHAM BENH     \n');
    printf('==============================================\n');
    for (int i = 0; i < 4; i++) {
        printf('Benh nhan %d | Tuoi: %d | BHYT: %d | Phi kham: %d VND | Luong: ', 
               i + 1, tuoi_benh_nhan[i], co_bao_hiem[i], phi_kham[i]);
        
        if (tuoi_benh_nhan[i] <= 0 || tuoi_benh_nhan[i] > 120) {
            printf('LOI DU LIEU\n');
        } else if (tuoi_benh_nhan[i] > 70) {
            printf('UU TIEN\n');
        } else {
            printf('THUONG\n');
        }
    }
    printf('----------------------------------------------\n');
    printf('Tong doanh thu thu phi thuc te: %d VND\n', tong_doanh_thu);
    printf('Tong so ca thuoc luong UU TIEN: %d\n', so_ca_uu_tien);
    printf('==============================================\n');

    return 0;
}