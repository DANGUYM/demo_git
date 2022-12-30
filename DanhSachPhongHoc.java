package bai06;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class DanhSachPhongHoc {
	private ArrayList<PhongHoc> ds;

	// khởi tạo constructor ds
	public DanhSachPhongHoc() {
		ds = new ArrayList<PhongHoc>();

	}

	/**
	 * 
	 * @param ph
	 * @return
	 */

	public boolean themPhongHoc(PhongHoc ph) {
		if (ds.contains(ph))
			return false;
		ds.add(ph);
		return true;

	}

	public String layToanBoDanhSach() {
		String s = "";
		for (PhongHoc ph : ds)
			s += ph + "\n";
		return s;

	}

	public String layDanhSachDatChuan() {
		String s = "";
		for (PhongHoc ph : ds) {
			if (ph.datChuan())
				s += ph + "\n";
			return s;
		}
		return s;

	}

	public PhongHoc timKiem(String maPhong) {
		for (PhongHoc ph : ds)
			if (ph.getMaPhong().equalsIgnoreCase(maPhong))
				return ph;
		return null;

	}

	public void sapXepTangTheoDayNha() {
		Collections.sort(ds, new Comparator<PhongHoc>() {

			@Override
			public int compare(PhongHoc o1, PhongHoc o2) {
				// TODO Auto-generated method stub
				return o1.getDayNha().compareToIgnoreCase(o2.getDayNha());
			}

		});

	}

	public void sapXepTheoDienTich() {
		Collections.sort(ds, new Comparator<PhongHoc>() {

			@Override
			public int compare(PhongHoc o1, PhongHoc o2) {
				// TODO Auto-generated method stub
				if (o1.getDienTich() > o2.getDienTich()) {
					return 1;
				} else if (o1.getDienTich() < o2.getDienTich()) {
					return -1;

				}
				return 0;
			}
		});

	}
}
