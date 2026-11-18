---
title: 'ECE 562 Project Checklist: Complex-Number ISA Extension'

---

# ECE 562 Project Checklist: Complex-Number ISA Extension

Software baseline vs ALU (Jay & Aiden) vs Accelerator (Kody & Ashish). **Report due Fri Dec 4.**

**Log every run:** save the raw output in `student-work/results/` with the config name, the date, and your name, and commit it the same day.

## Fri Oct 16:
- [ ] **All:** Ashish's code is the software baseline
- [ ] **All:** Everyone uses BaselineConfig (it is not the same as CourseRocketConfig)
- [ ] **All:** Same benchmark setup for everyone (same flags, same inputs, same checksum)
- [ ] **All:** Shared repo set up, everyone commits weekly
- [ ] **All:** Accelerator and ALU designs stay in separate configs

## Fri Oct 23: Baseline numbers
- [ ] **All:** Baseline cycles saved on BaselineConfig
- [ ] **Accel:** Course RoCC example (ROCCTest) runs
- [ ] **ALU:** Clamp8 example builds and runs

## Fri Oct 30: Designs compile
- [ ] **Accel:** ComplexAccelConfig builds
- [ ] **ALU:** CCMUL/CADD config builds
- [ ] **All:** Same 16/16 data format on both teams

## Fri Nov 6: First passing test
- [ ] **Accel:** acomplex_test passes
- [ ] **ALU:** CCMUL/CADD test passes

## Fri Nov 13: First comparison
- [ ] **Accel and ALU:** Full correctness tests pass
- [ ] **Accel and ALU:** First benchmark vs baseline saved
- [ ] **All:** Choose the final workload (vector add, vector multiply, FIR)

## Fri Nov 20: Freeze hardware
- [ ] **Accel and ALU:** Hardware frozen, no more changes
- [ ] **All:** Final benchmark run on all three configs
- [ ] **All:** Report outline started

## Fri Nov 27: Results and draft
- [ ] **All:** Results table done (software vs ALU vs accelerator)
- [ ] **All:** Report draft written

## Fri Dec 4: Report due
- [ ] **All:** Everyone reads the report, then submit the PDF
- [ ] **All:** Slides drafted for the presentation (Dec 7/9, confirm the date)